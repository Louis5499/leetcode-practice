class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> nextGreater;
        for (int num: nums2) {
            while (!stk.empty() && stk.top() < num) {
                nextGreater[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }
        while (!stk.empty()) {
            nextGreater[stk.top()] = -1;
            stk.pop();
        }
        
        for (int i=0; i<nums1.size(); i++) {
            nums1[i] = nextGreater[nums1[i]];
        }
        
        return nums1;
    }
};