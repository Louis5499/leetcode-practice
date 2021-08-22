class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (int num: arr) m[num]++;
        int uniqueNum = m.size();
        
        map<int, int> counts;
        for (const auto&[key, val]: m) {
            counts[val]++;
        }
        
        auto it = counts.begin();
        while (k > 0) {
            if (k - it->first*it->second >= 0) {
                k -= it->first*it->second;
                uniqueNum -= it->second;
            } else {
                return uniqueNum - k/it->first;
            }
            it++;
        }
        
        return uniqueNum;
    }
};