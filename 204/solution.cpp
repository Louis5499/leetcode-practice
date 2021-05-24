class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> notPrime(n, false);
        for (int i=2; i<n; i++) {
            if (notPrime[i] == false) {
                count++;
                for (int j=2; i*j<n; j++) {
                    notPrime[i*j] = true;
                }
            }
        }
        return count;
    }
};