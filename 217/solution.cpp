class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashMap;
        for (int val:nums) {
            auto iter = hashMap.find(val);
            if (iter != hashMap.end()) {
                return true;
            } else {
                hashMap.insert(val);
            }
        }
        return false;
    }
};