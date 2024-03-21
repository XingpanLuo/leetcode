/*
 * @lc app=leetcode.cn id=2671 lang=cpp
 * @lcpr version=30119
 *
 * [2671] 频率跟踪器
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class FrequencyTracker {
    unordered_map<int,int> m;
    unordered_map<int,int> freq;
public:
    FrequencyTracker() {
        m=unordered_map<int,int>();
        freq=unordered_map<int,int>();
        freq[1]=0;
    }
    
    void add(int number) {
        if(m.find(number)!=m.end()){
            freq[m[number]]--;
            m[number]++;
            freq[m[number]]++;
        }else{
            m[number]=1;
            freq[1]++;
        }
    }
    
    void deleteOne(int number) {
        if(m.find(number)!=m.end()){
            if(m[number]>0){
                freq[m[number]]--;
                m[number]--;
                freq[m[number]]++;
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        if(freq.find(frequency)!=freq.end()){
            if(freq[frequency]>0){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
// @lc code=end



