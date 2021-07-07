class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> arr;
        vector<double> ans;

        for (int i=0; i<k; i++) placement(arr, nums[i]);
        double midValue = (k&1) ? arr[k/2] : (arr[k/2-1] + arr[k/2])/2;
        ans.emplace_back(midValue);
        for (int i=k; i<nums.size(); i++) {
            // 1. remove element
            int removedElementIdx = findElement(arr, nums[i-k]);
            arr.erase(arr.begin()+removedElementIdx);
            
            // 2. place new element
            placement(arr, nums[i]);
            
            // 3. get mid value
            double midValue = (k&1) ? arr[k/2] : (arr[k/2-1] + arr[k/2])/2;
            ans.emplace_back(midValue);
        }
        return ans;
    }
    
    void placement(vector<double>& nums, int value) {
        if (nums.size() <= 0) {
            nums.emplace_back(value);
            return;
        }
        int i=0, j=nums.size()-1;
        while (i<=j) {
            int mid = i + (j-i)/2;
            if (nums[mid] > value) {
                j = mid-1;
            } else {
                i = mid+1;
            }
        }
        nums.insert(nums.begin() + i, value);
    }
    
    int findElement(vector<double>& nums, int value) {
        int i=0, j=nums.size()-1;
        while (i<=j) {
            int mid = i + (j-i)/2;
            if (nums[mid] > value) {
                j = mid-1;
            } else {
                i = mid+1;
            }
        }
        return j;
    }
};