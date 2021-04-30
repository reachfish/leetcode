/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 *
 * https://leetcode.com/problems/design-twitter/description/
 *
 * algorithms
 * Medium (31.76%)
 * Likes:    1299
 * Dislikes: 233
 * Total Accepted:    65.3K
 * Total Submissions: 205.6K
 * Testcase Example:
 '["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]\n'
 +
  '[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]'
 *
 * Design a simplified version of Twitter where users can post tweets,
 * follow/unfollow another user, and is able to see the 10 most recent tweets
 * in the user's news feed.
 *
 * Implement the Twitter class:
 *
 *
 * Twitter() Initializes your twitter object.
 * void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId
 * by the user userId. Each call to this function will be made with a unique
 * tweetId.
 * List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs
 * in the user's news feed. Each item in the news feed must be posted by users
 * who the user followed or by the user themself. Tweets must be ordered from
 * most recent to least recent.
 * void follow(int followerId, int followeeId) The user with ID followerId
 * started following the user with ID followeeId.
 * void unfollow(int followerId, int followeeId) The user with ID followerId
 * started unfollowing the user with ID followeeId.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet",
 * "getNewsFeed", "unfollow", "getNewsFeed"]
 * [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
 * Output
 * [null, null, [5], null, null, [6, 5], null, [5]]
 *
 * Explanation
 * Twitter twitter = new Twitter();
 * twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
 * twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1
 * tweet id -> [5]. return [5]
 * twitter.follow(1, 2);    // User 1 follows user 2.
 * twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
 * twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2
 * tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is
 * posted after tweet id 5.
 * twitter.unfollow(1, 2);  // User 1 unfollows user 2.
 * twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1
 * tweet id -> [5], since user 1 is no longer following user 2.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= userId, followerId, followeeId <= 500
 * 0 <= tweetId <= 10^4
 * All the tweets have unique IDs.
 * At most 3 * 10^4 calls will be made to postTweet, getNewsFeed, follow, and
 * unfollow.
 *
 *
 */

// @lc code=start
class Twitter {
 public:
  /** Initialize your data structure here. */
  Twitter() {}

  struct Tweet {
    int tweet_id;
    int post_index;
  };

  struct ExtTweet {
    int user_id;
    int tweet_id;
    int post_index;
    int local_index;

    bool operator<(const ExtTweet& other) const {
      return post_index < other.post_index;
    }
  };

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    postes_[userId].push_back({tweetId, next_post_index_++});
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
   * in the news feed must be posted by users who the user followed or by the
   * user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    priority_queue<ExtTweet> que;
    vector<int> result;
    const int kMaxCount = 10;
    result.reserve(kMaxCount);

    auto fn_push_last_post = [&](int uid) {
      auto it_postes = postes_.find(uid);
      if (it_postes == postes_.end()) {
        return;
      }

      const auto& postes = it_postes->second;
      if (postes.empty()) {
        return;
      }

      const auto& tw = postes.back();
      que.push({uid, tw.tweet_id, tw.post_index, int(postes.size()) - 1});
    };

    auto it = followees_.find(userId);
    if (it != followees_.end()) {
      for (auto uid : it->second) {
        fn_push_last_post(uid);
      }
    }
    fn_push_last_post(userId);

    while (!que.empty() && result.size() < kMaxCount) {
      auto t = que.top();
      que.pop();

      result.push_back(t.tweet_id);
      const auto& postes = postes_[t.user_id];
      if (t.local_index > 0) {
        const auto& tw = postes[--t.local_index];
        que.push({t.user_id, tw.tweet_id, tw.post_index, t.local_index});
      }
    }

    return result;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a
   * no-op. */
  void follow(int followerId, int followeeId) {
    if (followerId == followeeId) {
      return;
    }

    followees_[followerId].insert(followeeId);
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a
   * no-op. */
  void unfollow(int followerId, int followeeId) {
    followees_[followerId].erase(followeeId);
    if (followees_[followerId].empty()) {
      followees_.erase(followerId);
    }
  }

 private:
  unordered_map<int, unordered_set<int>> followees_;
  unordered_map<int, vector<Tweet>> postes_;
  int next_post_index_ = 1;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end
