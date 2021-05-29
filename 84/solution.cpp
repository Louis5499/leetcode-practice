class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        stk.push(-1);
        int maxArea = 0;
        for (int i=0; i<heights.size(); i++) {
            while (stk.top() != -1 && heights[stk.top()] >= heights[i]) {
                maxArea = calcMaxArea(stk, heights, i, maxArea);
            }
            stk.push(i);
        }
        
        while (stk.top() != -1) {
            maxArea = calcMaxArea(stk, heights, heights.size(), maxArea);
        }
        return maxArea;
    }
    int calcMaxArea(stack<int> &stk, vector<int>& heights, int right, int maxArea) {
        int curHeight = heights[stk.top()];
        stk.pop();
        int curWidth = right - stk.top() - 1;
        return max(maxArea, curHeight*curWidth);
    }
};