/*
 * @lc app=leetcode.cn id=2580 lang=cpp
 * @lcpr version=30120
 *
 * [2580] 统计将重叠区间合并成组的方案数
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
#include <cmath>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        if(ranges.size()==1) return 2;
        long long mod_num=1e9+7;
        vector<pair<int,int>> merge_ranges;
        auto ranges_compare=[](vector<int>&lhs,vector<int>&rhs){
            return lhs.at(0)<rhs.at(0);
        };
        sort(ranges.begin(),ranges.end(),ranges_compare);
        pair<int,int> merge_pair=make_pair(ranges[0][0],ranges[0][1]);
        int left=0,right=0;
        for(int i=1;i<ranges.size();i++){
            left=ranges[i][0];
            right=ranges[i][1];
            if(left>merge_pair.second){
                merge_ranges.push_back(merge_pair);
                merge_pair=make_pair(left,right);
            }else{
                if(right>merge_pair.second){
                    merge_pair.second=right;
                }
            }
        }
        merge_ranges.push_back(merge_pair);
        int merge_ranges_num=merge_ranges.size();
        int res=1;
        for(int i=0;i<merge_ranges_num;i++){
            res=(res*2)%mod_num;
        }
        return res%mod_num;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[6,10],[5,15]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[10,20],[2,5],[4,8]]\n
// @lcpr case=end

 */

