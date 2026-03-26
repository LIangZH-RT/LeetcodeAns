#pragma once


#include <vector>

class Leetcode33 {
public:
    int search(std::vector<int>& nums, int target) {
        int r = nums.size() - 1, l = 0, mid = r / 2, ans = -1;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == target) {
                ans = mid;
                return ans;
            }
            if (nums[mid] >= nums[l]) {
                if (nums[mid] > target && nums[l] <= target) { // 如果用等于会自动排除端点情况
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            else {
                if (nums[mid] < target && nums[r] >= target) {
                    l = mid + 1;
                }
                else r = mid - 1;
            }

        }
        return ans;
    }
};