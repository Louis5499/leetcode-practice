class SparseVector {
public:
    vector<pair<int, int>> arr;
    SparseVector(vector<int> &nums) {
        for (int i=0; i<nums.size(); i++) {
            arr.emplace_back(make_pair(i, nums[i]));
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum = 0;
        for (int i=0, j=0; i<arr.size() && j<vec.arr.size(); i++, j++) {
            if (arr[i].first < vec.arr[j].first) {
                j--;
            } else if (arr[i].first > vec.arr[j].first) {
                i--;
            } else {
                sum += arr[i].second*vec.arr[j].second;
            }
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);