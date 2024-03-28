/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30121
 *
 * [5] 最长回文子串
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
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        int left=0,right=0;
        int max_len=1;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i<n&&i+len-1<n;i++){
                int j=i+len-1;
                if(s[i]!=s[j]){
                    dp[i][j]=false;
                }else{
                    if(j-i<=2){
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
                if(dp[i][j]){
                    if(j-i+1>max_len){
                        max_len=j-i+1;
                        left=i;
                        right=j;
                    }
                }
            }
        }
        return s.substr(left,max_len);
    }
    
};
// @lc code=end



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

