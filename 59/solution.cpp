class Solution {
public:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> output(n, vector<int>(n, 0));
        int count = 1, pos = 0, i=0, j=-1;
        while (count <= pow(n,2)) {
            if (i+dirs[pos][0] >= n || i+dirs[pos][0] < 0 || j+dirs[pos][1] >= n || j+dirs[pos][1] < 0) {
                pos = (pos+1)%4;
                continue;
            }
            i += dirs[pos][0];
            j += dirs[pos][1];
            if (output[i][j] != 0) {
                i -= dirs[pos][0];
                j -= dirs[pos][1];
                pos = (pos+1)%4;
                continue;
            }
            output[i][j] = count++;
        }
        return output;
    }
};