#pragma once

#include <ctime>
#include <random>
#include <iostream>
#include <algorithm>

int* randomArray(int size, int max_value,int min_value = 0);

int randomnumber(int max, int min = 0);

std::vector<int> randomVector_sort(int size, int max_value, int min_value = 0);

void printArray(int* arr, int size);

std::vector<int> UniqueArray(int max, int min);