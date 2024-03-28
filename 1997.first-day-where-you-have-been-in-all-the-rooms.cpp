/*
 * @lc app=leetcode.cn id=1997 lang=cpp
 * @lcpr version=30121
 *
 * [1997] 访问完所有房间的第一天
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
class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n=nextVisit.size();
        int mod_num=1e9+7;
        vector<int> dp(n,0);
        dp[0]=0;
        for(int i=1;i<n;i++){
            dp[i]=(dp[i-1]+1+dp[i-1]-dp[nextVisit[i-1]]+1)%mod_num;
            //dp[i-1] 第一次走到i-1
            //1 从i-1走到nextVisit[i-1]
            //dp[i-1]-dp[nextVisit[i-1]] 从nextVisit[i-1]再次走到i-1
            //1 从i-1走到i
            if(dp[i]<0) dp[i]+=mod_num; //出现取余和减法，要考虑可能出现减法结果为负
        }
        return dp[n-1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,0,0,0,0,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,0]\n
// @lcpr case=end

 */

