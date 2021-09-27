class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int num: arr) m[num]++;
        
        sort(arr.begin(), arr.end());
        
        for (int i=0; i<arr.size(); i++) {
            if (m[arr[i]] == 0) continue;
            if (arr[i] < 0 && arr[i]%2 != 0) return false;
            int cand = arr[i] < 0 ? arr[i]/2 : arr[i]*2;
            if (m[cand] == 0) return false;
            m[cand]--;
            m[arr[i]]--;
        }
        
        return true;
    }
};