// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=135 lang=cpp
 * @lcpr version=30119
 *
 * [135] 分发糖果
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int num=ratings.size();
        if(num==0) return 0;
        if(num==1) return 1;
        vector<int> score=vector<int>(num,1);
        for(int i=1;i<num;i++){
            if(ratings[i]>ratings[i-1]){
                score[i]=score[i-1]+1;
            }
        }
        for(int i=num-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                score[i]=max(score[i],score[i+1]+1);
            }
        }
        int res=accumulate(score.begin(),score.end(),0);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

 */

