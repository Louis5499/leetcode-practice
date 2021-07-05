class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> hm;
        for (auto stone : stones) {
            hm[stone] = unordered_set<int>{};
        }
        hm[stones[0]].insert(1);
        int target = stones[stones.size()-1];
        for(int i = 0; i < stones.size()-1; i++) {
            int stone = stones[i];
            for (auto step : hm[stone]) {
                int reach = stone + step;
                if (stone + step == target) {
                    return true;
                }
                if (hm.count(reach)) {
                    hm[reach].insert(step);
                    hm[reach].insert(step+1);
                    if(step > 0) hm[reach].insert(step-1);
                }
            }
        }
        
        return false;
    }
};