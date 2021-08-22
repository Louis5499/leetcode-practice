import java.io.*;
import java.nio.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.nio.charset.StandardCharsets;

// Feel free to add any imports you need

public class Solution {
    /**
     * A class which wraps a raw binary WAL and reconstructs DML Events.
     */
    public static class WAL {
        /**
         * Construct the WAL
         * @param input the raw binary WAL
         */
        private ArrayList<String> arr = new ArrayList<>();
        public WAL(byte[] input) {
            int i=0;
            while (i < input.length) {
                long epoch = ByteBuffer.wrap(input).getLong(i); // 0 -> 7 bytes
                int mid = ByteBuffer.wrap(input).get(i+8); // 8 byte
                String opName = "";
                if (mid == 0) opName = "INSERT";
                else if (mid == 1) opName = "UPSERT";
                else opName = "DELETE";

                short keyLens = ByteBuffer.wrap(input).getShort(i+9); // 9 -> 10 bytes
                 // 11 -> 11 + keyLen bytes
                byte[] keyBytes = Arrays.copyOfRange(input, i+11, i+11+keyLens);
                String key = new String(keyBytes, StandardCharsets.US_ASCII);

                short valLens = 0;
                String val = "";
                if (mid != 2) {
                    // If op == "DELETE", there's no value

                    // i+11+keyLens -> i+13+keyLens
                    valLens = ByteBuffer.wrap(input).getShort(i+11+keyLens);
                    byte[] valBytes = Arrays.copyOfRange(input, i+13+keyLens, i+13+keyLens+valLens);
                    val = new String(valBytes, StandardCharsets.US_ASCII);
                }

                i += 11 + keyLens; // offset to next start point
                String output = Long.toString(epoch) + "|" + opName + "|" + key;
                if (valLens > 0) {
                    output += "|" + val;
                    i += 2 + valLens; // "short" byte size for valLen + byte size for val
                }
                arr.add(output);
            }
        }
        
        /**
         * Retrieve all events contained within the WAL as their string values in time order
         * DML Event String Format: "<epoch_milli>|<message_name>|<key>|<value>"
         * 
         * @return a time-ordered sequence of DML Event strings
         */
        public ArrayList<String> getEvents() {
            return arr;
        }
    }
    public static class InputParser {