// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2549 lang=cpp
 * @lcpr version=30119
 *
 * [2549] 统计桌面上的不同数字
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
#include <memory>
#include <algorithm>
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int distinctIntegers(int n) {
        vector<int> count(n+1,0);
        count[n]=1;
        for(int k=0;k<n;k++){
            for(int x=2;x<=n;x++){
                if(count[x]==0) continue;
                for(int i=2;i<x;i++){
                    if(x%i==1){
                        count[i]=1;
                    }
                }
            }
        }
        return std::accumulate(count.begin(),count.end(),0);
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=distinctIntegers
// paramTypes= ["number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

