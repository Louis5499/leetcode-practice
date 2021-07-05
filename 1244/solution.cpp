class Leaderboard {
public:
    unordered_map<int, int> m;
    set<pair<int, int>> s;
    Leaderboard() {}
    
    void addScore(int playerId, int score) {
        s.erase({m[playerId], playerId});
        m[playerId] += score;
        s.insert({m[playerId], playerId});
    }
    
    int top(int K) {
        int res = 0, c = 0;
        for(auto it = s.rbegin(); it!=s.rend() && c < K; it++) {
            res+=(it->first);
            c++;
        }
        return res;
    }
    
    void reset(int playerId) {
        s.erase({m[playerId], playerId});  
        m[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */