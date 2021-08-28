#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'countPrimeStrings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING inputStr as parameter.
 */
 
 bool isPrime(string &inputStr, int i, int j) {
     int num = stoi(inputStr.substr(i, j-i));
     if (num < 2) return false;
     for (int i=2; i<=sqrt(num); i++) {
         if (num%i == 0) return false;
     }
     return true;
 }

int countPrimeStrings(string inputStr) {
    int n = inputStr.size();
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for (int i=1; i<=n; i++) {
        if (inputStr[i-1] != '0' && isPrime(inputStr, i-1, i)) dp[i] = dp[i-1];
        if (i>=2 && inputStr[i-2] != '0' && isPrime(inputStr, i-2, i)) dp[i] += dp[i-2];
        if (i>=3 && inputStr[i-3] != '0' && isPrime(inputStr, i-3, i)) dp[i] += dp[i-3];
        if (i>=4 && inputStr[i-4] != '0' && isPrime(inputStr, i-4, i)) dp[i] += dp[i-4];
        if (i>=5 && inputStr[i-5] != '0' && isPrime(inputStr, i-5, i)) dp[i] += dp[i-5];
        if (i>=6 && inputStr[i-6] != '0' && isPrime(inputStr, i-6, i)) dp[i] += dp[i-6];
    }
    
    return dp[n];
}

int main()