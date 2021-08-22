class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int res = 0, right = 0, n = light.size();
        for (int i=0; i<n; i++) {
            res += (right = max(right, light[i])) == i+1;
        }
        return res;
    }
};