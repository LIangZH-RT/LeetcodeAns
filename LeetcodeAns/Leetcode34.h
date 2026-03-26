#pragma once
#include <vector>



class Leetcode_34 {
public:
	std::vector<int> searchRange(std::vector<int>& nums, int target) {
		return std::vector<int>{ FL(nums,target),FR(nums,target) };
	};
	
	//Ñ°ÕÒ×óÓÒ±ß½ç ²¢·ÇÔÚ×óÓÒ°ë²¿Ñ°ÕÒ
	int FL(std::vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1, mid = 0, ans = -1;

		while (l <= r) {
			mid = (l + r) / 2;
			if (nums[mid] >= target) {
				if (nums[mid] == target) {
					ans = mid;
				}
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		return ans;
	}

	int FR(std::vector<int>nums, int target) {
		int l = 0, r = nums.size() - 1, mid = 0, ans = -1;
		
		while (l <= r) {
			mid = (l + r) / 2;
			if (nums[mid] <= target) {
				if (nums[mid] == target) {
					ans = mid;
				}
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		return ans;
	}
public:
	std::vector<int> rightAnswer(std::vector<int>& nums, int target) {
		int first = -1, last = -1;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == target) {
				if (first == -1) first = i;
				last = i;
			}
		}
		return { first, last };
	}


};


