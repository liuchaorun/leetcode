#include <vector>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i-1]) return nums[i];
        }
        return nums[0];
    }
};
// @lc code=end

