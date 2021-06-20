/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int res = 0;
        while (n > 0) {
            int tmp = min(read4(buf), n);
            res += tmp;
            buf += tmp;
            if (tmp < 4) break;
            n -= 4;
        }
        return res;
    }
};