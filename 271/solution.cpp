class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string output = "";
        for (string str: strs) {
            output += to_string(str.length()) + '/' + str;
        }
        return output;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        for (int i=0; i<s.length();) {
            int slashIdx = s.find('/', i);
            if (slashIdx != s.npos) {
                int num = stoi(s.substr(i, i-slashIdx));
                string str = s.substr(slashIdx+1, num);
                ans.emplace_back(str);
                i = slashIdx+num+1;
            }
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));