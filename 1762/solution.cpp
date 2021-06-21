class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int curMax = heights.back();
        vector<int> output = { (int)heights.size()-1 };
        for (int i=heights.size()-2; i>=0; i--) {
            if (heights[i] > curMax) output.push_back(i); 
            curMax = max(curMax, heights[i]);
        }
        return vector<int>(output.rbegin(), output.rend());
    }
};