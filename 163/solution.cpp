class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> output;
        int left = lower, right = lower;
        for (int num: nums) {
            right = min(num-1, upper);
            if (left > right) {
                left = num+1;
                continue;
            }
            string result = (left == right) ? to_string(left) : (to_string(left) + "->" + to_string(right));
            output.emplace_back(result);
            left = num+1;
        }
        if (left <= upper) {
            string result = (left == upper) ? to_string(left) : (to_string(left) + "->" + to_string(upper));
            output.emplace_back(result);
        }
        return output;
    }
};