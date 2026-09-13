class Twitter {
  private:
  vector<pair<int, int>> post;
  map<pair<int, int>, bool> follows;
  
  public:
  
    Twitter() {
        // Code Here
        post.clear();
        follows.clear();
        
    }

    void postTweet(int userId, int tweetId) {
        // Code Here
        post.push_back(make_pair(userId, tweetId));
    }

    // Retrieve the 10 most recent tweet ids
    vector<int> getNewsFeed(int userId) {
        // Code Here
        int count=0;
        int i=post.size()-1;
        vector<int> ans;
        while(i>=0 and count< 10){
            if(post[i].first== userId or follows[make_pair(userId, post[i].first)]){
                ans.push_back(post[i].second);
                count++;
            }
            i-=1;
        }
        return ans;
    }

    // Follower follows a followee.
    void follow(int followerId, int followeeId) {
        // Code Here
        follows[make_pair(followerId, followeeId)]=1;
    }

    // Follower unfollows a followee. 
    void unfollow(int followerId, int followeeId) {
        // Code Here
        follows[make_pair(followerId, followeeId)]=0;
    }
};