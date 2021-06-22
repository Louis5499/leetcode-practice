class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        vector<int> buckets(10, 0);

        for (int i=0; i<str.length(); i++) {
            buckets[str[i] - '0'] = i;
        }
        
        for (int i=0; i<str.length(); i++) {
            for (int j=9; j>str[i]-'0'; j--) {
                if (buckets[j] > i) {
                    swap(str[buckets[j]], str[i]);
                    return stoi(str);
                }
            }
        }
        return num;
    }
};