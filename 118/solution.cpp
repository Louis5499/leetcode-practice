class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;
        for (int i=1; i<=numRows; i++) {
            vector<int> layer(i, 1);
            int lastCol = 0;
            for (int j=1; j<i-1; j++) {
                layer[j] = output[output.size()-1][lastCol] + output[output.size()-1][lastCol+1];
                lastCol++;
            }
            output.emplace_back(layer);
        }
        return output;
    }
};