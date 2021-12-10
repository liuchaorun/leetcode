#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
 public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();
    int ret = 1;
    int inc = 1, dec = 0, pre = 1;
    for (int i = 1; i < n; i++) {
      if (ratings[i] >= ratings[i - 1]) {
        dec = 0;
        pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
        ret += pre;
        inc = pre;
      } else {
        dec++;
        if (dec == inc) {
          dec++;
        }
        ret += dec;
        pre = 1;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  vector<int> ratings = {1, 3, 2, 2, 1};
  Solution s;
  cout << s.candy(ratings);
  return 0;
}
