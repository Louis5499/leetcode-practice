class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        pair<int,int> curr({0,0});
        vector<vector<int>> result;
        multiset<pair<int,int>> seq;
        for(auto p:buildings){
            seq.emplace(make_pair(p[0],-p[2]));
            seq.emplace(make_pair(p[1],p[2]));
        }
        multiset<int> height({0});
        for(auto p:seq){
            if(p.second<0)height.emplace(-p.second);
            else height.erase(height.find(p.second));
            if(*height.rbegin()!=curr.second){
                curr.first=p.first;
                curr.second=*height.rbegin();
                result.push_back(vector<int>{curr.first, curr.second});
            }
        }
        return result;
    }
};