class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> indices(n);
        for (int i=0; i<n; i++) indices[i] = i; // Since we don't move the element in nums array, we use indice for index transformation during computation.
        mergesort(indices, 0, n, result, nums);
        return result;
    }
    
    void mergesort(vector<int>& indices, int left, int right, vector<int>& result, vector<int>& nums) {
        if (right - left <= 1) return;
        int mid = (left+right)/2;
        mergesort(indices, left, mid, result, nums);
        mergesort(indices, mid, right, result, nums);
        merge(indices, left, right, mid, result, nums);
    }
    
    void merge(vector<int>& indices, int left, int right, int mid, vector<int>& result, vector<int>& nums) {
        int i = left;
        int j = mid;
        vector<int> tmp;
        
        while (i<mid && j<right) {
            if (nums[indices[i]] <= nums[indices[j]]) {
                result[indices[i]] += j - mid;
                tmp.push_back(indices[i]);
                i++;
            } else {
                tmp.push_back(indices[j]);
                j++;
            }
        }
        
        while (i<mid) {
            result[indices[i]] += j-mid;
            tmp.push_back(indices[i]);
            i++;
        }
        while (j<right) {
            tmp.push_back(indices[j]);
            j++;
        }
        
        move(tmp.begin(), tmp.end(), indices.begin() + left);
    }
};