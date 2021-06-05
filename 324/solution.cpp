class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        auto midPtr = nums.begin() + n/2;
        nth_element(nums.begin(), midPtr, nums.end());
        int mid = *midPtr;
        
        #define A(i) nums[(1+2*(i)) % (n|1)]
        
        int i=0, j=0, k=n-1;
        while (j<=k) {
            if (A(j) < mid) swap(A(j), A(k--));
            else if (A(j) > mid) swap(A(i++), A(j++));
            else j++;
        }
    }
};