#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<double, int> res;
        int ans = 0, r = 0;
        for (int i = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];
            res.clear();
            r = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (points[j][0] == x) {
                        r++;
                    } else {
                        res[(points[j][1] - y) * 1.0/(points[j][0] * 1.0 - x)]++;
                    }
                }
            }
            ans = max(ans, r);
            for (auto& r:res) {
                if (r.second > ans) {
                    ans = r.second;
                }
            }
        }
        return ans + 1;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> d = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    Solution solution;
    cout<<solution.maxPoints(d);
    return 0;
}
