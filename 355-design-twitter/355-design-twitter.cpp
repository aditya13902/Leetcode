class Twitter {
public:
    unordered_map<int,set<pair<int,int>>>mp;
    unordered_map<int,set<int>>mp2;
    int cnt;
    Twitter() {
        cnt=0;
    }
    
    void postTweet(int userId, int tweetId) {
        mp[userId].insert({cnt,tweetId});
        cnt++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(auto ele:mp[userId]){
            pq.push(ele);
        }
        for(auto curr:mp2[userId]){
            for(auto ele:mp[curr]){
                pq.push(ele);
            }
        }
        for(int i=0;pq.size() && i<10;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int id1, int id2) {
        mp2[id1].insert(id2);
    }
    
    void unfollow(int id1, int id2) {
        if(mp2[id1].find(id2)==mp2[id1].end()){
            return;
        }
        mp2[id1].erase(id2);
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