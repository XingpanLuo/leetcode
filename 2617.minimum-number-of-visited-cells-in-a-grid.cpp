// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2617 lang=cpp
 * @lcpr version=30119
 *
 * [2617] 网格图中最少访问的格子数
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
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        dist[0][0] = 1;
        vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>> row(m), col(n);

        auto update = [](int& x, int y) {
            if (x == -1 || y < x) {
                x = y;
            }
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                while (!row[i].empty() && row[i].top().second + grid[i][row[i].top().second] < j) {
                    row[i].pop();
                }
                if (!row[i].empty()) {
                    update(dist[i][j], dist[i][row[i].top().second] + 1);
                }

                while (!col[j].empty() && col[j].top().second + grid[col[j].top().second][j] < i) {
                    col[j].pop();
                }
                if (!col[j].empty()) {
                    update(dist[i][j], dist[col[j].top().second][j] + 1);
                }
                if (dist[i][j] != -1) {
                    row[i].emplace(dist[i][j], j);
                    col[j].emplace(dist[i][j], i);
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=minimumVisitedCells
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// [[3,4,2,1],[4,2,3,1],[2,1,0,0],[2,4,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,4,2,1],[4,2,1,1],[2,1,1,0],[3,4,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,0],[1,0,0]]\n
// @lcpr case=end

 */
