class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        auto it = products.begin();
        vector<vector<string>> res;
        string cur = "";
        for (char c: searchWord) {
            cur += c;
            it = lower_bound(it, products.end(), cur);
            vector<string> suggested;
            for (int i=0; i<3 && it+i != products.end(); i++) {
                string tmp = *(it+i);
                if (tmp.find(cur)) break;
                suggested.emplace_back(tmp);
            }
            res.emplace_back(suggested);
        }
        return res;
    }
};