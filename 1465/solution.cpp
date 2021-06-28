class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int maxRec = 0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int hMax = max(horizontalCuts[0], h - horizontalCuts.back());
        int vMax = max(verticalCuts[0], w - verticalCuts.back());
        for (int i=0; i<horizontalCuts.size()-1; i++) {
            hMax = max(hMax, horizontalCuts[i+1] - horizontalCuts[i]);
        }
        for (int i=0; i<verticalCuts.size()-1; i++) {
            vMax = max(vMax, verticalCuts[i+1] - verticalCuts[i]);
        }
        return (long)hMax*vMax%1000000007;
    }
};