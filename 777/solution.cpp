class Solution {
public:
    bool canTransform(string start, string end) {
        string c1 = "", c2 = "";
        for (int i=0; i<start.length(); i++) {
            if (start[i] != 'X') c1 += start[i];
        }
        
        for (int i=0; i<start.length(); i++) {
            if (end[i] != 'X') c2 += end[i];
        }
        if (c1 != c2) return false;
        
        for (int i=0, j=0; i<start.length() && j < end.length();) {
            if (start[i] == 'X') i++;
            else if (end[j] == 'X') j++;
            else {
                if ((start[i] == 'R' && i > j) || (start[i] == 'L' && i < j)) return false;
                i++;
                j++;
            }
        }
        return true;
    }
};