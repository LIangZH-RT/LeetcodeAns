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
	vector<vector<int>> ans;
	vector<int> nums = randomVector_sort(6, 4);
	printArray(nums.data(), nums.size());
	ans = Leetcode78_90().subsetsWithDup2(nums);
	for (auto i : ans) {
		std::cout << "{";
		for (auto j : i) {
			std::cout << j << ",";
		}
		std::cout << "}" << std::endl;
	}
}