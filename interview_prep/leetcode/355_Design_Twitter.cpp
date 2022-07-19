class Twitter {
    
    unordered_map<int, set<pair<int, int>>> newsFeed;
    unordered_map<int, vector<pair<int, int>>> tweetsForUser;
    unordered_map<int, set<int>> followersForUser;
    int timeCounter;
    
public:
    Twitter() {
        
        timeCounter = 0;
        
    }
    
    void postTweet(int userId, int tweetId) {
        
        tweetsForUser[userId].push_back({timeCounter, tweetId});
        for(auto follower : followersForUser[userId]) {
            newsFeed[follower].insert({timeCounter, tweetId});
        }
        newsFeed[userId].insert({timeCounter, tweetId});
        timeCounter--; // Decrementing time to sort in reverse order
    }
    
    vector<int> getNewsFeed(int userId) {
        
        vector<int> feedForUser;
        for(auto i : newsFeed[userId]) {
            feedForUser.push_back(i.second);
            if (feedForUser.size() == 10)
                break;
        }
        
        timeCounter--; // Decrementing time to sort in reverse order
        return feedForUser;
        
    }
    
    void follow(int followerId, int followeeId) {
        
        if (followersForUser[followeeId].count(followerId) != 0)
            return;
        
        followersForUser[followeeId].insert(followerId);
        
        // Insert tweets of followee into follower's feed
        for(auto tweet : tweetsForUser[followeeId]) {
            newsFeed[followerId].insert(tweet);
        }
        
        timeCounter--; // Decrementing time to sort in reverse order
        
    }
    
    void unfollow(int followerId, int followeeId) {
        
        followersForUser[followeeId].erase(followerId);
        
        for(auto tweet : tweetsForUser[followeeId]) {
            newsFeed[followerId].erase(tweet);
        }
        
        timeCounter--; // Decrementing time to sort in reverse order
        
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
