class Solution {
    typedef vector<pair<int, int>> Pii;
    typedef Pii::iterator Pit;
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        Pii nums_(n);
        for(int i = 0; i < n; ++i)
            nums_[i] = {nums[i], i};
        merge(nums_.begin(), nums_.end(), res);
        return res;
    }
    
    void merge(Pit begin, Pit end, vector<int>& res){
        if(end - begin <= 1)
            return;
        auto mid = begin + (end - begin) / 2;
        merge(begin, mid, res);
        merge(mid, end, res);
        for(auto i = begin, j = mid; i != mid; ++i){
            while(j != end && i->first > j->first)
                ++j;
            res[i->second] += j - mid;
        }
        inplace_merge(begin, mid, end);
    }
};