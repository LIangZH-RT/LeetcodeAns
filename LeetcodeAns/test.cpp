#include "test_solution.h"


void test_solution::test(int n, int size, int max, int min) {
	int index = 1;
	while (n != 0) {
		
		std::cout << "the no."<<index << std::endl;
		std::vector<int> v = randomVector_sort(size, max,min);
		int target = randomnumber(max, min);
		Leetcode_34 sol;
		std::vector<int> ans= sol.searchRange(v, target);

		std::cout << "Faster" << std::endl;
		std::cout << "{" << ans[0] << "," << ans[1] << "}" << std::endl;
		
		std::vector<int> rightans = sol.rightAnswer(v, target);

		std::cout << "Right" << std::endl;
		std::cout << "{" << rightans[0] << "," << rightans[1] << "}" << std::endl;
		
		std::cout<<std::endl;
		n--; index++;
	}
}


void test_solution::test78() {
	vector<vector<int>> ans;
	vector<int> nums = UniqueArray(5, 1);
	ans = Leetcode78_90::subsets(nums);
	for (auto i : ans) {
		std::cout << "{";
		for (auto j : i) {
			std::cout << j << ",";
		}
		std::cout << "}" << std::endl;
	}
}

void test_solution::test90() {
	vector<vector<int>> ans1,ans2;
	vector<int> nums = randomVector_sort(6, 4);
	printArray(nums.data(), nums.size());
	ans1 = Leetcode78_90().subsetsWithDup2(nums);
	ans2 = Leetcode78_90().subsetsWithDup1(nums);

	cout << "----- S1 -----" << endl;
	for (auto i : ans1) {
		std::cout << "{";
		for (auto j : i) {
			std::cout << j << ",";
		}
		std::cout << "}" << std::endl;
	}
	cout << "----- S2 -----" << endl;
	for (auto i : ans2) {
		std::cout << "{";
		for (auto j : i) {
			std::cout << j << ",";
		}
		std::cout << "}" << std::endl;
	}
}


void test_solution::test42() {
	vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	vector<int> h2 = { 4,2,0,3,2,5 };
	cout << Leetcode42_11::trap(h2);
}

void test_solution::test11() {
	vector<int> h1 = {1,8,6,2,5,4,8,3,7};
	vector<int> h2 = { 1,1,0,14,20 };
	cout << Leetcode42_11::maxArea(h2);
}


void test_solution::test746() {
	vector<int> cost = { 10, 15, 20 };
	cout << Leetcode_dfs::minCostClimbingStairs(cost);
}