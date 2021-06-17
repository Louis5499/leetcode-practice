class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> cumulatedSumForBegin(n+1, 0);
        vector<int> cumulatedSumForEnd(n+1, 0);
        
        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += cardPoints[i];
            cumulatedSumForBegin[i+1] = sum;
        }
        
        sum = 0;
        for (int i=0; i<n; i++) {
            sum += cardPoints[n-i-1];
            cumulatedSumForEnd[i+1] = sum;
        }
        
        int maxSum = 0;
        for (int i=0; i<=k; i++) {
            maxSum = max(maxSum, cumulatedSumForBegin[i] + cumulatedSumForEnd[k-i]);
        }
        
        return maxSum;
    }
};