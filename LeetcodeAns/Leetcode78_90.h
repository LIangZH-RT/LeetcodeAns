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
		f90(0, path, nums, ans);
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

	static void f90(int i, vector<int> &path,vector<int> &nums, vector<vector<int>> &ans) {
		ans.push_back(path);

		for ( int k = i; i < nums.size(); i++) {
			if (i > k && nums[i] == nums[i - 1] ) continue;
			path.push_back(nums[i]);
			f90(i + 1, path, nums, ans);
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
			vector<int> temp;
			for (int k = 0; k < size; k++) {
				temp.push_back(path[k]);
			}
			ans.push_back(temp);
			return;
		}

		// ÕÒµ½ÖØ¸´¶Î [i, j)
		int j = i + 1;
		while (j < nums.size() && nums[j] == nums[i]) {
			j++;
		}
		
		f90_2(j, path, nums, ans, size);
		for (; i < j; i++) {
			path[size++] = nums[i];
			f90_2(j, path, nums, ans, size );
		}
	}
	
};
