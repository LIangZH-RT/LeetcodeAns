#pragma once
#include <bits/stdc++.h>

class Leetcode_dfs{
public:
	static int mincostTickets(std::vector<int> days, std::vector<int> costs) {
		int way[] = { 1, 7, 30 };
		std::vector<int> dp(days.size(), -1);
		//return f983_1(days, costs, 0);

		f983_2_2(days, costs, way, 0, dp);
	}
	/*
	以下f983 方法都是从顶开始的递归 标准为从底开始 底部依赖少
	
	例如
	f(n-1) 只依赖于越界位置f(n) 底部状态简单分析
	*/

	static int f983_1(std::vector<int> days, std::vector<int> costs, int i) {
		if (i == days.size()) {
			return 0;
		}

		int cost1 = costs[0] + f983_1(days, costs, i + 1);

		int j = i; int length = days.size();
		while (j < length && days[j] < days[i] + 7) j++;

		int cost2 = costs[1] + f983_1(days, costs, j);

		j = i;
		while (j < length && days[j] < days[i] + 30) j++;
		int cost3 = costs[2] + f983_1(days, costs, j);

		return std::min({ cost1, cost2, cost3 });
	}

	static int f983_2(std::vector<int> days, std::vector<int> costs, int way[], int i) {
		if (i == days.size()) {
			return 0;
		}
		int ans = days.size() * costs[2];
		for (int j =0 , k = i; j < 3; j++) {
			while (k < way[j] && days[k] < days[i]+way[j]) {
				k++;
			}
			int cost = costs[j] + f983_2(days , costs , way , k);
			ans = std::min({ ans, cost });
		}
		return ans;
	}

	static int f983_1_2(std::vector<int> days,std::vector<int> costs,int i,int dp[]) {
		if (i == days.size()) {
			return 0;
		}

		if (dp[i] != -1) {
			return dp[i];
		}

		int cost1 = costs[0] + f983_1_2(days, costs, i + 1, dp);

		int j = i; int length = days.size();
		while (j < length && days[j] < days[i] + 7) j++;

		int cost2 = costs[1] + f983_1_2(days, costs, j, dp);

		j = i;
		while (j < length && days[j] < days[i] + 30) j++;
		int cost3 = costs[2] + f983_1_2(days, costs, j, dp);

		dp[i] = std::min({ cost1, cost2, cost3 });
		return dp[i];
	}

	static int f983_2_2(std::vector<int> days, std::vector<int> costs,int way[], int i, std::vector<int>& dp) {
		if (i == days.size()) {
			return 0;
		}

		if (dp[i] != -1) {
			return dp[i];
		}
		int ans = INT_MAX;

		for (int j = 0, k = i; j < 3; j++) {
			while (k < days.size() && days[k] < days[i] + way[j]) {
				k++;
			}

			ans = std::min({ ans, costs[j] + f983_2_2(days, costs, way, k, dp) });
		}

		return dp[i]= ans;
	}

	static int f983_3_1(std::vector<int> days, std::vector<int> costs,int i) {
		int n = days.size();
		std::vector<int> dp(n + 1, -1);
		dp[n] = 0;

		for (int i = n - 1; i > 0 ; i++) {
			int cost1 = costs[0] + dp[i + 1];

			int j = i;
			while (j >= 0 && days[i] + 7 > days[j]) j++;

			int cost2 = costs[1] + dp[j];

			int j = i;
			while (j >= 0 && days[i] + 30 > days[j]) j++;

			int cost3 = costs[2] + dp[j];

			dp[i] = std::min({ cost1, cost2, cost3 });
		}
		

		return dp[0];
	}

	static int f983_3_2(std::vector<int> days, std::vector<int> costs, int i,int ways[]) {
		int n = days.size();
		std::vector<int> dp(n + 1, -1);

		for (int i = n - 1; i > 0; i--) {
			for (int j = i, int k = 0; k < 3; k++) {
				while ( j < n && days[i] + ways[k] > days[j]) {
					j++;
				}
				int cost = costs[k] + dp[j];
				dp[i] = std::min({ dp[i], cost });
			}
			
		}
		return dp[0];
	}

	static int climbStairs(int n) {
		std::vector<int> dp(n + 1, -1);
		return f70_1(n);
	}

	static int f70_1(int n) {
		if (n == 1) return 1;
		if (n == 2) return 2;

		return f70_1(n - 1) + f70_1(n - 2);
	}

	static int f70_2(int n, std::vector<int>& dp) {
		if (n == 1) return 1;

		if (n == 2) return 2;

		if (dp[n] != -1) {
			return dp[n];
		}

		return dp[n] = f70_2(n - 1, dp) + f70_2(n - 2, dp);

	}

	static int minCostClimbingStairs(std::vector<int> cost) {
		std::vector<int> dp(cost.size() + 1, -1);
		return f746_1(cost, cost.size());
	}

	static int f746_1(std::vector<int> cost, int n) {
		if (n == 0 || n ==1 ) {
			return 0;
		}
		
		int cost1 = cost[n-1] + f746_1(cost , n - 1);

		int cost2 = cost[n-2] + f746_1(cost, n - 2);

		return std::min({ cost1, cost2 });
	}


	 static  int rob(std::vector<int> nums) {

		 int ans = f89(nums,0);

		 return ans;
	}

	 static int f89(std::vector<int> nums,int i) {
		if(i >= nums.size()) return 0;

		int m = nums[i] + f89(nums, i + 2);

		// 100 1 1 100


	 }

	
};
