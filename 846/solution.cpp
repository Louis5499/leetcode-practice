class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> count;
        for (auto &perHand: hand) count[perHand]++;
        
        for (auto &c: count) {
            if (c.second > 0) {
                for (int i=groupSize-1; i>=0; i--) {
                    if ((count[c.first+i] -= count[c.first]) < 0) return false;
                }
            }
        }
        return true;
    }
};