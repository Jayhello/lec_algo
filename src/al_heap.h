//
// Created by wenwen on 2022/5/17.
//
#pragma once
#include "al_comm.h"

//https://leetcode.cn/problems/last-stone-weight/
int lastStoneWeight(const vector<int>& stones);

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums):keep_(k){
        for(auto n : nums)
            add(n);
    }

    int add(int val) {
        if(que_.size() < keep_){
            que_.push(val);
        }else{
            if(que_.top() < val){
                que_.pop();
                que_.push(val);
            }
        }

        return que_.top();
    }

private:
    int keep_;
    priority_queue<int, vector<int>, greater<int>> que_;
};

//https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/
vector<int> getLeastNumbers(vector<int>& arr, int k);

//https://leetcode.cn/problems/g5c51o/
vector<int> topKFrequent(vector<int>& nums, int k);

class Twitter {
public:
    Twitter() {
    }

    struct FeedInfo{
        int tweetId, ascId;

        bool operator < (const FeedInfo& rhs)const{
            return ascId > rhs.ascId;
        }
    };

    constexpr static int LEN = 10;

    void postTweet(int userId, int tweetId) {
        uidTweetListMap[userId].push_front({tweetId, globalAscId++});
        follow(userId, userId);
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<FeedInfo> minQue;

        const auto& followUidSet = uidFollowUidSetMap[userId];
        for(const auto& uid : followUidSet){
            const auto& tweetList = uidTweetListMap[uid];
            for(const auto& tid : tweetList){
                if(minQue.size() < LEN){
                    minQue.push(tid);
                }else{
                    if(tid.ascId > minQue.top().ascId){
                        minQue.pop();
                        minQue.push(tid);
                    }else{
                        break;
                    }
                }
            }
        }

        vector<int> res;
        while(not minQue.empty()){
            res.insert(res.begin(), minQue.top().tweetId);
            minQue.pop();
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        uidFollowUidSetMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if(uidFollowUidSetMap.count(followerId)){
            uidFollowUidSetMap[followerId].erase(followeeId);
        }
    }

//    typedef vector<FeedInfo>                         FeedList;
    typedef list<FeedInfo>                          FeedList;

    typedef unordered_map<int, FeedList>            UidTweetListMap;
    typedef unordered_map<int, unordered_set<int>>  UidFollowUidSetMap;

    int globalAscId  = 0;
    UidFollowUidSetMap   uidFollowUidSetMap;
    UidTweetListMap      uidTweetListMap;
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    return nullptr;
}

