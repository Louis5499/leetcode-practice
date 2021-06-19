class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> stk;
        vector<int> output(n, 0);
        int beingOccupied = 0;
        for (string &log: logs) {
            stringstream ss(log);
            string temp, temp2, temp3;
            getline(ss, temp, ':');
            getline(ss, temp2, ':');
            getline(ss, temp3, ':');

            pair<int, int> item = make_pair(stoi(temp), stoi(temp3));
            if (temp2 == "start") {
                stk.push(item);
            } else {
                pair<int, int> lastItem = stk.top(); stk.pop();
                int timeOccpuied = item.second - lastItem.second + 1;
                output[item.first] += timeOccpuied;
                
                if (!stk.empty()) {
                    output[stk.top().first] -= timeOccpuied;
                }
            }
        }
        return output;
    }
};