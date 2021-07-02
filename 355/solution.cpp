class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    int time = 0;
    unordered_map<int, vector<pair<int, int>>> posts;
    unordered_map<int, unordered_set<int>> followings;
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        posts[userId].emplace_back(make_pair(time++, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        for (auto post: posts[userId]) pq.push(post);
        
        for (auto following: followings[userId]) {
            for (auto post: posts[following]) pq.push(post);
        }
        
        int n = 10;
        vector<int> output;
        while (n-- && !pq.empty()) {
            output.emplace_back(pq.top().second);
            pq.pop();
        }
        return output;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followings[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */