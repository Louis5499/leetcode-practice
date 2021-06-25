class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> mapping(n, 0);
        vector<vector<bool>> connected(n, vector<bool>(n, false));
        
        for (vector<int> &road: roads) {
            mapping[road[0]]++;
            mapping[road[1]]++;
            
            connected[road[0]][road[1]] = true;
            connected[road[1]][road[0]] = true;
        }
        
        int maxResult = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                int lines = mapping[i] + mapping[j] - connected[i][j];
                maxResult = max(lines, maxResult);
            }
        }
        return maxResult;
    }
};