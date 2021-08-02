class FindSumPairs {
public:
    vector<int> arr1, arr2;

    unordered_map<int,int> m2;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1; arr2 = nums2;
        for (auto &i: arr2) m2[i]++;
    }
    
    void add(int index, int val) {
        int prev = arr2[index];
        arr2[index] += val;
      
        m2[prev]--;
        if(m2[prev] == 0) m2.erase(prev);

        m2[arr2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for (auto &i: arr1){
            if(m2.find(tot-i) != m2.end()){
                ans += m2[tot-i];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */