class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProd = nums[0], maxProd = nums[0];
        int maxProf = maxProd;
        
        for (int i=1; i<nums.size(); i++){
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