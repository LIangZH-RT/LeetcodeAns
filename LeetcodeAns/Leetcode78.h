#pragma once

#include<vector>
#include<list>

using std::vector;

class Leetcode78 {
public:
	
	static vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> path;
		f(nums, 0, path, ans);
		return ans;
	}

	static void f(vector<int>& nums,int i,vector<int> &path,vector<vector<int>> &ans) {
		if (i == nums.size()) {
			ans.push_back(path);
			return;
		}
		path.push_back(nums[i]);
		f(nums, i + 1, path, ans);
		path.pop_back();
		f(nums, i + 1, path, ans);
	}
	
};
