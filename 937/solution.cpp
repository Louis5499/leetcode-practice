class Solution {
public:
    static int compare(string &s1, string &s2) {
        string trimS1 = s1.substr(s1.find(" ")+1);
        string trimS2 = s2.substr(s2.find(" ")+1);
        if (trimS1 == trimS2) {
            trimS1 = s1.substr(0, s1.find(" "));
            trimS2 = s2.substr(0, s2.find(" "));
        }
        return trimS1 < trimS2;
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digitLogs;
        for (int i=0; i<logs.size(); i++) {
            string log = logs[i];
            bool isDigit = false;
            for (int j=0; j<log.size(); j++) {
                if (log[j] == ' ') {
                    isDigit = log[j+1] >= '0' && log[j+1] <= '9';
                    break;
                }
            }
            if (isDigit) {
                digitLogs.emplace_back(log);
                logs.erase(logs.begin()+i);
                i--;
            }
        }
        
        sort(logs.begin(), logs.end(), compare);
        logs.insert(logs.end(), digitLogs.begin(), digitLogs.end());
        return logs;
    }
    
};