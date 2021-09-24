class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for (int num: asteroids) {
            if (num > 0) stk.push_back(num);
            else {
                while (!stk.empty() && stk.back() > 0 && stk.back() < abs(num)) stk.pop_back();
                if (stk.empty() || stk.back() < 0) stk.push_back(num);
                else if (stk.back() == abs(num)) stk.pop_back();
            }
        }
        return stk;
    }
};