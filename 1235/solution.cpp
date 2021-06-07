class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        map<int, int> times;
        unordered_map<int, vector<pair<int, int>>> jobs;
        for (int i=0; i<startTime.size(); i++) {
            times[startTime[i]] = 0;
            jobs[startTime[i]].push_back({ endTime[i], profit[i] }); // More than one jobs exist in a time point
        }
        int maxProfit = 0;
        for (auto it = rbegin(times); it != rend(times); it++) {
            for (auto job: jobs[it->first]) {
                auto nit = times.lower_bound(job.first);
                maxProfit = max(maxProfit, (nit == end(times) ? 0 : nit->second) + job.second);
            }
            it->second = maxProfit;
        }
        return maxProfit;
    }
};