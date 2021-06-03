class Solution {
public:
    vector<int> arr;
    Solution(vector<int>& nums) {
        arr = vector<int>(nums.begin(), nums.end());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffle(arr.begin(), arr.end());
        for (int i=0; i<shuffle.size(); i++) {
            int pos = rand()%(shuffle.size() - i);
            swap(shuffle[i+pos], shuffle[i]);
        }
        return shuffle;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */