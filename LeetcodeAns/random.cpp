#include "random.h"
#include <iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;


int* randomArray(int size, int max_value, int min_value) {
	int* arr = new int[size];

	static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
	std::uniform_int_distribution<int> dist(min_value, max_value);

	for (int i = 0; i < size; i++) {
		arr[i] = dist(rng);
	}


	return arr;
}

vector<int> UniqueArray(int max,int min) {
	if (max < min) {
		cout << "max should be greater than min" << endl;
		throw std::out_of_range("max should be greater than min");
	}

	vector<int> nums(max - min + 1);

	for (int i = 0; i < nums.size(); i++) {
		nums[i] = min + i;
	}

	return nums;
}

void printArray(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int randomnumber(int max, int min) {
	static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
	std::uniform_int_distribution<int> dist(min, max);
	return dist(rng);
}

std::vector<int> randomVector_sort(int size, int max_value, int min_value)
{	
	std::vector<int> vec(size);
	for (int i = 0; i < size; i++) {
		vec[i] = randomnumber(max_value, min_value);
	}
	std::sort(vec.begin(),vec.end());
	return vec;
}
