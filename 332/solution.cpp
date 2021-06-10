class Solution {
public:
    vector<string> route;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>> parents;
        for (vector<string> perTicket: tickets) parents[perTicket[0]].insert(perTicket[1]);
        
        iterate(parents, "JFK");
        return vector<string>(route.rbegin(), route.rend());
    }    
    
    void iterate(map<string, multiset<string>> &parents, string stop) {
        while (!parents[stop].empty()) {
            string next = *parents[stop].begin();
            parents[stop].erase(parents[stop].begin());
            iterate(parents, next);
        }
        route.emplace_back(stop);
    }
};