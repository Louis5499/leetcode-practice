class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> count;
        for (string cpdomain: cpdomains) {
            auto blank = cpdomain.find(" ");
            int perCount = stoi(cpdomain.substr(0, blank));
            cpdomain = cpdomain.substr(blank+1);
            
            count[cpdomain] += perCount;
            
            while (cpdomain.find(".") != string::npos) {
                cpdomain = cpdomain.substr(cpdomain.find(".")+1);
                count[cpdomain] += perCount;
            }
        }
        
        vector<string> result;
        for (auto it = count.begin(); it != count.end(); it++) {
            result.emplace_back(to_string(it->second) + " " + it->first);
        }
        return result;
    }
};