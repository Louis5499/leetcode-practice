class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> orderedA(A.begin(), A.end());
        for (int i=0; i<B.size(); i++) {
            auto element = orderedA.upper_bound(B[i]);
            if (element == orderedA.end()) element = orderedA.begin();
            A[i] = *element;
            orderedA.erase(element);
        }
        return A;
    }
};