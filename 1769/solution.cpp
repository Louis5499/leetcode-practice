class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> result(boxes.size(), 0);
        
        // -->
        int ops = 0, balls = 0;
        for (int i=0; i<boxes.size(); i++) {
            result[i] += ops;
            balls += (boxes[i] == '1' ? 1 : 0);
            ops += balls;
        }
        
        ops = 0;
        balls = 0;
        for (int i=boxes.size() - 1; i >= 0; i--) {
            result[i] += ops;
            balls += (boxes[i] == '1' ? 1 : 0);
            ops += balls;
        }
        
        return result;
    }
};