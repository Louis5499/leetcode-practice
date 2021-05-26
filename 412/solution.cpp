class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n+1, "");
        for (int i=1; i<=n; i++) {
            if (i%15 == 0) ans[i] = "FizzBuzz";
            else if (i%5 == 0) ans[i] = "Buzz";
            else if (i%3 == 0) ans[i] = "Fizz";
            else {
                ans[i] = to_string(i);
            }
        }
        return vector<string>(ans.begin()+1, ans.end());
    }
};