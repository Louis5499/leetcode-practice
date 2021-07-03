class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        for (int i=1; i<rating.size()-1; i++) {
            int less[2] = {}, greater[2] = {};
            for (int j=0; j<rating.size(); j++) {
                if (rating[i] < rating[j]) ++less[j>i];
                if (rating[i] > rating[j]) ++greater[j>i];
            }
            res += less[1]*greater[0] + greater[1]*less[0];
        }
        return res;
    }
};

/* Another solution
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), res = 0;
        // Step1. Use two set to store ratings that we've seen, e.g.: [1,2,3,4]
        // iterate:  1    /    2      /   3      /    4
        // lset:          /    1      /  1,2     / 1,2,3
        // rset: 1,2,3,4  /  2,3,4    /  3,4     /    4
        set<int> lset, rset(rating.cbegin(), rating.cend());
        for(int i=1; i<n ;i++){
            lset.insert(rating[i-1]); //Put prev value into the lset
            rset.erase(rating[i-1]);  //Erase prev value from the rset
             
            // Step 2. for rating[i] < rating[j] < rating[k]
            int d1 = std::distance(lset.cbegin(), lset.lower_bound(rating[i])); //Check how many values are smaller than rating[i]
            int d2 = std::distance(rset.upper_bound(rating[i]), rset.cend());   //Check how many values are bigger than rating[i]
            if(d1 > 0 && d2 > 0)
                res += d1*d2;
            
            // Step 3. for rating[i] > rating[j] > rating[k]
            int d3 = std::distance(lset.upper_bound(rating[i]), lset.cend()); //Check how many values are bigger than rating[i]
            int d4 = std::distance(rset.cbegin(), rset.lower_bound(rating[i])); //Check how many values are smaller than rating[i]
            if(d3 > 0 && d4 > 0)
                res += d3*d4;     
        }
        return res;
    }
};
*/