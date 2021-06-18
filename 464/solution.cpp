class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (maxChoosableInteger)*(maxChoosableInteger+1)/2;
        if (desiredTotal < 2) return true;
        else if (sum < desiredTotal) return false;
        else if (sum == desiredTotal) return maxChoosableInteger%2;
        return dfs(maxChoosableInteger, desiredTotal, 0);
    }
    
    int state[1<<20] = {};
    bool dfs(int m, int d, int k) {
        if(state[k] != 0) return state[k] > 0;
        
        if (d <= 0) return false;
        
        for (int i=0; i<m; i++) {
            if (!(k&(1<<i)) && !dfs(m, d-i-1, k|(1<<i))) {
                state[k] == 1;
                return true;
            }
        }
        
        state[k] = -1;
        return false;
    }
};