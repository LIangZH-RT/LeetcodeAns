#pragma once

#include<bits/stdc++.h>

using std::vector;

class Leetcode78_90 {
public:
	
	static vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		vector<int> path;
		f78(nums, 0, path, ans);
		return ans;
	}

	static vector<vector<int>> subsetsWithDup1(vector<int>& nums) {

		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		vector<int> path;
		f90(0, path, nums, ans, 0);
		return ans;
	};



	static void f78(vector<int>& nums,int i,vector<int> &path,vector<vector<int>> &ans) {
		if (i == nums.size()) {
			ans.push_back(path);
			return;
		}
		path.push_back(nums[i]);
		f78(nums, i + 1, path, ans);
		path.pop_back();
		f78(nums, i + 1, path, ans);
	}

	static void f90(int i, vector<int> &path,vector<int> &nums, vector<vector<int>> &ans, int size) {
		if (i == nums.size()) {
			ans.push_back(path);
			return;
		}

		int j = i + 1;
		while ( j < nums.size() && nums[i] == nums[j] ) {
			j++;
		}
		
		f90(j, path, nums, ans, size);
		for (;i < j ;i++) {
			path.push_back(nums[i]);
			f90(j, path, nums, ans, size);

			path.pop_back();
		}


	}


	static vector<vector<int>> subsetsWithDup2(vector<int>& nums) {

		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;

		vector<int> path(nums.size());

		f90_2(0, path, nums, ans, 0);
		return ans;
	}

	static void f90_2(int i, vector<int>& path,
		vector<int>& nums,
		vector<vector<int>>& ans,
		int size) {

		if (i == nums.size()) {
			ans.push_back(vector<int>(path.begin(), path.begin() + size));
			return;
		}

		// 找到重复段 [i, j)
		int j = i + 1;
		while (j < nums.size() && nums[j] == nums[i]) {
			j++;
		}

		//  选0个当前数
		f90_2(j, path, nums, ans, size);

		//  选1~k个当前数
		for (int k = 1; k <= j - i; k++) {
			path[size + k - 1] = nums[i];   // 写入对应位置
			f90_2(j, path, nums, ans, size + k);
		}
	}
	
};
