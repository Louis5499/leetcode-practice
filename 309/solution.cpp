class Solution {
public:
	int maxProfit(vector<int>& prices){
		if (prices.size() <= 1) return 0;
        int s0, s1, s2;
		s1 = -prices[0];
		s0 = 0;
		s2 = INT_MIN;
		for (int i = 1; i < prices.size(); i++) {
            int prev_s0 = s0;
			s0 = max(prev_s0, s2);
            s2 = s1 + prices[i];
			s1 = max(s1, prev_s0 - prices[i]);
		}
		return max(s0, s2);
	}
};