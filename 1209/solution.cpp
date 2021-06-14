class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int, char>> stk;
        stk.push_back({0, '#'});
        for (char c: s) {
            if (stk.back().second != c) stk.push_back(pair<int, char>{1, c});
            else if (++stk.back().first == k) {
                stk.pop_back();
            }
        }
        string ans = "";
        for (auto &item: stk) {
            ans.append(item.first, item.second);
        }
        return ans;
    }
};