class Solution {
public:
    int minDeletions(string s) {
        vector<int> counts(26, 0);
        for (char c: s) {
            counts[c-'a']++;
        }
        
        unordered_map<int, int> m;
        int movement = 0;
        for (int i=0; i<counts.size(); i++) {
            if (counts[i] == 0) continue;
            int runningCount = counts[i];
            while (m.find(runningCount) != m.end() && runningCount > 0) {
                movement++;
                runningCount--;
            }
            m[runningCount] = i;
        }
        
        return movement;
    }
};