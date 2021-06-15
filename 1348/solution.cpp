class TweetCounts {
public:
    unordered_map<string, multiset<int>> all;
    TweetCounts() {
    }
    
    void recordTweet(string tweetName, int time) {
        all[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int d;
        if (freq == "minute") d = 60;
        else if (freq == "hour") d = 3600;
        else d = 86400;
        
        vector<int> result((endTime-startTime)/d + 1);
        const auto s = all.find(tweetName);
        if (s != all.end()) {
            for (auto it = s->second.lower_bound(startTime); it != s->second.end() && *it <= endTime; it++) {
                result[(*it-startTime)/d]++;
            }
        }
        return result;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */