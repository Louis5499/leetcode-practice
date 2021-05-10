class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProd = nums[0], maxProd = nums[0];
        int maxProf = maxProd;
        
        for (int i=1; i<nums.size(); i++){
            
            // When incoming element is negative, maxProd * neg element would become neg.
            // in order to keep maxProd to be max since past, we need to swap minProd & maxProd
            if (nums[i] < 0) {
                swap(minProd, maxProd);
            }
            
            maxProd = max(maxProd * nums[i], nums[i]);
            minProd = min(minProd * nums[i], nums[i]);
            
            if (maxProf < maxProd) maxProf = maxProd;
        }
        
        return maxProf;
    }
};