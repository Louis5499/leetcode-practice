class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task: tasks) freq[task-'A']++;
        
        sort(freq.begin(), freq.end(), greater<int>());
        
        int maxCount = freq[0];
        int idleTime = (maxCount-1)*n;
        
        for (int i=1; i<=25; i++) {
            idleTime -= min(maxCount-1, freq[i]);
        }
        idleTime = max(0, idleTime);
        
        return idleTime + tasks.size();
    }
};