class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        long long m = points.size(), n = points[0].size();
        vector<long long> pre(n);
        for (int i=0; i<n; i++) pre[i] = points[0][i];
        for (int i=1; i<m; i++) {
            vector<long long> lft(n, 0), rgt(n, 0), cur(n, 0);
            lft[0] = pre[0];
            rgt[n-1] = pre[n-1];
            for (int j=1; j<n; j++) {
                lft[j] = max(lft[j-1]-1, pre[j]);
            }
            for (int j=n-2; j>=0; j--) {
                rgt[j] = max(rgt[j+1]-1, pre[j]);
            }
            for (int j = 0; j < n; ++j){
                cur[j] = points[i][j] + max(lft[j], rgt[j]);
            }
            pre = cur;
        }
        
        long long maxResult = 0;
        for (int i=0; i<pre.size(); i++) {
            maxResult = max(maxResult, pre[i]);
        }
        return maxResult;
    }
};