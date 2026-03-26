#pragma once

#include <bits/stdc++.h>
#include <math.h>

class Leetcode42_11 {
public:
	static int trap(std::vector<int> &height) {
		
		return f42(height);
	}

	static int f42(std::vector<int> &height) {
		if (height.size() == 1) return 0;
		if (height.size() == 2) return 0;
		if (height.size() == 3) {
			int a = min(height[0], height[2]) - height[1] ;
			return a > 0 ? a : -1;
		}
		int L = 1; int R = height.size() - 2;
		int maxL = height[L - 1]; int maxR = height[R + 1];
		int ans = 0;
		for (; L <= R ;) {
			if (maxL > maxR) {
				ans += maxR - height[R] > 0 ? maxR - height[R] : 0;
				maxR = max(maxR, height[R]);
				R--;
			}
			else {
				ans += maxL - height[L] > 0 ? maxL - height[L] : 0;
				maxL = max(maxL, height[L]);
				L++;
			}
		}
		return ans;
	}

	 static int max(int a, int b) {
		return a >= b ? a : b;
	 }
	 static int min(int a, int b) {
		 return a >= b ? b : a;
	 }

	 static int maxArea(std::vector<int>& height) {
		
		 return f11(height);
	 }

	 static int f11(std::vector<int>& height) {

		 int L = 0, R = height.size() - 1;
		 int ans = 0;
		 while (L <= R) {
			 ans = max(ans, min(height[L], height[R]) * (R - L ));
			 if (height[L] > height[R]) {
				 R--;
			 }
			 else {
				 L++;
			 }
		 }

		 return ans;
	 }

};