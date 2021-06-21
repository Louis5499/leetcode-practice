class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0, j=0;
        vector<vector<int>> output;
        while (i<firstList.size() && j<secondList.size()) {
            if (firstList[i][0] > secondList[j][1]) {
                j++;
                continue;
            } else if (firstList[i][1] < secondList[j][0]) {
                i++;
                continue;
            }
            output.emplace_back(vector<int>{ max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1]) });
            if (firstList[i][1] >= secondList[j][1]) j++;
            else i++;
        }
        return output;
    }
};