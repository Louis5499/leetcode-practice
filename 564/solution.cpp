class Solution {
public:
    string nearestPalindromic(string n) {
        int sn = n.size();
        if(sn == 1) return string(1, --n[0]);
        int half_sn = (sn+1)/2;
        long half_val = stol(n.substr(0, half_sn));
        vector<long> candidates = { (long)(pow(10, sn)-1), (long)(pow(10, sn-1)-1), (long)(pow(10, sn)+1), (long)(pow(10, sn-1)+1) };
        findOtherCandidates(candidates, sn, half_val);
        sort(candidates.begin(), candidates.end()); //return smaller value if there is a tie
        
        string ans;
        long val = stol(n), min_diff = INT_MAX;
        for(long candidate : candidates) {
            if(candidate == val) continue;
            long diff = labs(val - candidate);
            if(diff < min_diff) {
                min_diff = diff;
                ans = to_string(candidate);
            }
        }
        return ans;
    }
    
private:
    void findOtherCandidates(vector<long> &candidates, int n, long val) {
        vector<long> fmdc = {val, val-1, val+1}; //candidates for flipping mid digit
        for(long c : fmdc) {
            string rev = to_string(c);
            if(n % 2) rev.pop_back();
            reverse(rev.begin(), rev.end());
            candidates.push_back(stol(to_string(c)+rev));
        }
    }
};

