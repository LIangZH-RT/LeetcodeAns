#pragma once

#include<vector>

class Leetcode_162 {
public:
	int findPeakElement2(std::vector<int>& nums) {
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] > nums[mid + 1])
				r = mid - 1;
			else
				l = mid + 1;
		}
		return r;
	}
};
