/*
 * @lc app=leetcode.cn id=455 lang=cpp
 * @lcpr version=30119
 *
 * [455] 分发饼干
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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int, vector<int>, greater<int>> gpq;
        priority_queue<int, vector<int>, greater<int>> spq;
        for (auto& i : g) {
            gpq.push(i);
        }
        for (auto& i : s) {
            spq.push(i);
        }
        int res = 0;
        while (!gpq.empty() && !spq.empty()) {
            int gi = gpq.top();
            int si = spq.top();
            if (si >= gi) {
                gpq.pop();
                spq.pop();
                res++;
            } else {
                spq.pop();
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n[1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[1,2,3]\n
// @lcpr case=end

 */

