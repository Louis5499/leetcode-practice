class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& user, vector<int>& t, vector<string>& site) {
      unordered_map<string, map<int, string>> m;
      unordered_map<string, int> cnt;
      int m_cnt = 0;
      string res;
      for (auto i = 0; i < user.size(); ++i) m[user[i]][t[i]] = site[i];
      for (auto u : m) {
        unordered_set<string> ts;
        for (auto it = begin(u.second); it != end(u.second); ++it)
          for (auto it1 = next(it); it1 != end(u.second); ++it1)
            for (auto it2 = next(it1); it2 != end(u.second); ++it2)
              ts.insert(it->second + "$" + it1->second + "#" + it2->second);
        for (auto s : ts) ++cnt[s];
      }
      for (auto t : cnt) {
        if (t.second >= m_cnt) {
          res = res == "" || m_cnt < t.second ? t.first : min(res, t.first);
          m_cnt = t.second;
        }
      }
      auto p1 = res.find("$"), p2 = res.find("#");
      return { res.substr(0, p1), res.substr(p1 + 1, p2 - p1 - 1), res.substr(p2 + 1) };
    }
};