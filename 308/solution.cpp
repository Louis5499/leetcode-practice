class NumMatrix {
public:
    vector<vector<int>> mat;
    vector<vector<int>> tree;
    int m, n;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        if (m == 0 || n == 0) return;
        mat = vector<vector<int>>(m, vector<int>(n, 0));
        tree = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                update(i, j, matrix[i][j]);
            }  
        }
    }
    
    void update(int row, int col, int val) {
        if (m == 0 || n == 0) return;
        int delta = val - mat[row][col];
        mat[row][col] = val;
        for (int i=row+1; i<=m; i+=i&(-i)) {
            for (int j=col+1; j<=n; j+=j&(-j)) {
                tree[i][j] += delta;
            }  
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (m == 0 || n == 0) return 0;
        return sum(row2+1, col2+1) + sum(row1, col1) - sum(row1, col2+1) - sum(row2+1, col1);
    }
    
    int sum(int row, int col) {
        int sum = 0;
        for (int i=row; i>0; i -= i&(-i)) {
            for (int j=col; j>0; j -= j&(-j)) {
                sum += tree[i][j];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */