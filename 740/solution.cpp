class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> counts(n, 0);
        for (int num: nums) counts[num] += num;
        
        int take = 0, skip = 0;
        for (int i=0; i<n; i++) {
            int takeI = skip + counts[i];
            int skipI = max(skip, take);
            take = takeI;
            skip = skipI;
        }
        return max(skip, take);
    }
};