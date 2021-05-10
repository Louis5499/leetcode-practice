class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> sol(num+1, 0);
        for (int i=0; i<num+1; i++) {
            // consider the whole seq as (the last element) + (seq without last element)
            sol[i] = sol[i>>1] + (i&1);
        }
        return sol;
    }
};