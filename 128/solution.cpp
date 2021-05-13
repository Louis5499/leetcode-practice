class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end()), searched;
        
        int longest = 0;
        for (int i: nums) {
            if (searched.find(i) != searched.end()) continue;
            searched.insert(i);
            int j = i - 1, k = i + 1;
            while (s.find(j) != s.end()) searched.insert(j--);
            while (s.find(k) != s.end()) searched.insert(k++);
            longest = max(longest, k - 1 - j);
        }
        return longest;
    }
};