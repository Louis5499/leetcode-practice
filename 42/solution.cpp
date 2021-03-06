class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(height);
        vector<int> right(height);
        
        for (int i=1; i<n; i++) {
            int j = n-i-1;
            left[i] = max(left[i], left[i-1]);
            right[j] = max(right[j], right[j+1]);
        }
        
        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += min(left[i], right[i]) - height[i];
        }
        return sum;
    }
};