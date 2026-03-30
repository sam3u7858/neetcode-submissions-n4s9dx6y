class Twitter {
public:
    int count;
    unordered_map<int, vector<vector<int>>> tweetMap;
    unordered_map<int, set<int>> followMap;

    Twitter() {
        count = 0; // this to track the time that post
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count++, tweetId}) ;// push to tweet
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        auto compare = [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0]; // ascending (smaller first)
        };
        
        priority_queue<vector<int>, vector<vector<int>>,  decltype(compare)> minHeap(compare);
        followMap[userId].insert(userId); // add self as follower
        for(int f: followMap[userId]){
            // Get feed from follower feed
            if(tweetMap.count(f)){ // if "F" exist, which is a userID
                // get all the tweets from the user id
                const vector<vector<int>>& tweets = tweetMap[f];
                int index = tweets.size() -  1;
                // push to minheap so the tweet could be sort in ascending order
                minHeap.push({tweets[index][0], tweets[index][1], f, index});
                // timestamp, tweetId, userId (poster), index
                // So in this case, we compare 2 thing, (1) timestamp (2) index
                // since we want smaller first, so timestamp will be first
                // We need to know which user is first but not sorting all the post
                // => using minheap the "sort" the timestamp, then we get the post in minheap
            }
        }

        while(!minHeap.empty() && result.size() < 10){
                // add the post into result;
                const vector<int> currentPost = minHeap.top();
                minHeap.pop();
                result.push_back(currentPost[1]); // tweetID
                int index = currentPost[3];

                if(index > 0 ){
                    // add self post
                    const vector<int>& tweet = tweetMap[currentPost[2]][index - 1];
                    minHeap.push({tweet[0], tweet[1], currentPost[2], index -1});
            }
        }

        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
