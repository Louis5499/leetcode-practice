class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sv(26, 0), pv(26, 0), ans;
        
        if (s.size() < p.size()) return ans;
        
        for (int i=0; i<p.size(); i++) {
            sv[charToInt(s[i])]++;
            pv[charToInt(p[i])]++;
        }
        
        if (sv == pv) ans.push_back(0);
        
        
        for (int i=p.size(); i<s.size(); i++) {
            
            // New element has come
            sv[charToInt(s[i])]++;
            
            // Remove the old first element
            sv[charToInt(s[i-p.size()])]--;
            
            if (pv == sv) {
                ans.push_back(i-p.size()+1);
            }
        }
        
        return ans;
    }
    
    int charToInt(char c) {
        return c - 'a';
    }
};