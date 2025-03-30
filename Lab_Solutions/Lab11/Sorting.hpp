/*
 * File: main.cpp
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 10
 * Created: March 21, 2025
 */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// static class for sorting stuff - primarily merge sort
class Sorting {

private:

	// performs mergesort on the arr with start and end indices specified
	template<typename T>
	static T* mergesort(T* arr, int start, int end);

	// performs a merge of 2 sorted arrays, from start - mid, and mid + 1 - end
	template<typename T>
	static T* merge(T* arr, int start, int mid, int end);

public:

	Sorting() = delete; // enforce static class

	// performs a merge sort on an T array of n elements
	template <typename T> 
	static T* mergesort(T* arr, int n);

	// determines if an array is sorted or not
	template <typename T> 
	static bool isSorted(T* arr, int n);

	// prints an array to the screen
	template <typename T>
	static void printArray(T* arr, int n);

	// test funciton for array sorting
	template <typename T>
	static bool testSort(T* arr, int n);

	static bool testSortFromCSV(const std::string& filename, int upperBoundLines);
};

template <typename T>
T* Sorting::mergesort(T* arr, int start, int end) {

	if (end <= start) return arr;

	int mid = (start + end) / 2;
	mergesort(arr, start, mid);
	mergesort(arr, mid + 1, end);
	return merge(arr, start, mid + 1, end);
}

template<typename T>
T* Sorting::merge(T* arr, int start, int mid, int end) {

	// we're going to use a little bit of auxillary space for ease of use
	// something like gap/shell sort would work and be in place, but is kind of complex
	// memory is infinite anyhow

	// temp vars
	int l = start, r = mid;

	int size = end - start + 1;
	T* tempArr = new T[size];

	for (int i = 0; i < size; i++) {

		if (l >= mid) {
			// Left subarray exhausted
			tempArr[i] = arr[r++];
		}
		else if (r > end) {
			// Right subarray exhausted
			tempArr[i] = arr[l++];
		}
		else if (arr[l] <= arr[r]) {
			tempArr[i] = arr[l++];
		}
		else {
			tempArr[i] = arr[r++];
		}
	}

	for (int i = 0; i < size; i++) {
		arr[start + i] = tempArr[i];
	}

	delete[] tempArr;
	return arr;
}

template <typename T>
T* Sorting::mergesort(T* arr, int n) {

	return mergesort(arr, 0, n - 1);
}

template <typename T>
bool Sorting::isSorted(T* arr, int n) {

	for (int i = 0; i < n - 1; i++) {

		if (arr[i] > arr[i + 1]) return false;
	}

	return true;
}

template <typename T>
void Sorting::printArray(T* arr, int n) {

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
bool Sorting::testSort(T* arr, int n) {
	Sorting::mergesort(arr, n);
	//printArray(arr, n);
	bool success = Sorting::isSorted(arr, n);
	std::cout << "Sorted successfully: "
		<< (success ? "YES" : "NO")
		<< std::endl << std::endl;
	return success;
}

bool Sorting::testSortFromCSV(const std::string& filename, int upperBoundLines = 1000000) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error opening file: " << filename << "\n";
		return false;
	}

	std::string line;
	int lineNumber = 1;

	while (std::getline(file, line) && lineNumber < upperBoundLines) {
		std::stringstream ss(line);
		std::vector<int> values;
		std::string item;

		while (std::getline(ss, item, ',')) {
			std::stringstream converter(item);
			int number;
			if (converter >> number) {
				values.push_back(number);
			}
		}

		std::cout << "Testing array from line " << lineNumber << ":\n";
		if (!values.empty()) {
			auto success = testSort(values.data(), values.size());

			if (!success) {
				std::cout << "Line " << lineNumber << " failed!" << std::endl;
				return false;
			}
		}
		else {
			std::cout << "Error: Line " << lineNumber << " contains no integers or invalid format.\n\n";
		}

		lineNumber++;
	}

	std::cout << "passed all tests" << std::endl;
	file.close();
	return true;
}