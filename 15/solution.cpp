class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        std::sort(nums.begin(), nums.end());
        
        for (int i=0; i<nums.size(); i++) {
            int front = i+1;
            int back = nums.size() - 1;
            int target = -nums[i];

            if (target < 0) break;

            while (front < back) {
                int sum = nums[front] + nums[back];

                if (sum < target) front++;
                else if (sum > target) back--;
                else {
                    vector<int> triplets(3, 0);
                    triplets[0] = nums[i];
                    triplets[1] = nums[front];
                    triplets[2] = nums[back];
                    
                    res.push_back(triplets);
                    
                    // Skip the duplicate nums
                    while(front < back && nums[front] == triplets[1]) front++;
                    
                    // Skip the duplicate nums
                    while(front < back && nums[back] == triplets[2]) back--;
                }
            }
            
            // Skip the duplicate nums
            while (i < nums.size() - 1 && nums[i+1] == nums[i]) i++;
        }
        
        return res;
    }
};