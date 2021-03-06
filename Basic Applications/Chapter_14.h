#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>

#include "MyLinkedList.h"

/*
This file currently includes:
	14.1:
		std::vector<int> IntersectTwoSortedArrays(const std::vector<int>& A, const std::vector<int>& B)
*/

std::vector<int> IntersectTwoSortedArrays(const std::vector<int>& A,
	const std::vector<int>& B){

	std::vector<int> intersectVector;
	for (unsigned int i = 0; i < A.size(); ++i){
		if (i == 0 || A[i] != A[i - 1]) {	// if we are looking at the first value, OR if the current value does not equal the value before it in the Array A[]
			for (int b : B){				// for each int value b in B
				if (A[i] == b){
					intersectVector.emplace_back(A[i]);
					break;
				}
			}
		}
	}
	return intersectVector;
}

void chapter14_1(){
	std::vector<int> tempVec1 = { 1, 2, 4, 5, 6 };
	std::vector<int> tempVec2 = { 0, 2, 3, 4 };

	std::vector<int> intersectVector = IntersectTwoSortedArrays(tempVec1, tempVec2);

	std::cout << "The intersection of \n{ ";
	for (auto i : tempVec1){
		std::cout << i << " ";
	}
	std::cout << "}\nand\n{ ";
	for (auto i : tempVec2){
		std::cout << i << " ";
	}
	std::cout << "}\nis:\n{ ";

	for (auto i : intersectVector) {
		std::cout << i << " ";
	}
	std::cout << "}";
}

void CountOccurrences(std::string inputString){
	std::sort(inputString.begin(), inputString.end());

	int count = 1;
	for (unsigned int i = 1; i < inputString.size(); i++){
		if (inputString[i] == inputString[i-1]){
			count++;
		}else{
			std::cout << "(" << inputString[i - 1] << ", " << count << "),";
			count = 1;
		}
	}
	std::cout << "(" << inputString[inputString.size() - 1] << ", " << count << ")" << std::endl;
}

void chapter14_2(){
	std::cout << "Please enter a string of characters, this will count the occurance of each character." << std::endl;
	std::string inputString = "";
	std::cin >> inputString;
	std::cin.get();
	CountOccurrences(inputString);
}

void bucketSort(std::string inputString){
	MyLinkedList<char> buckets[26];
	buckets[2].push_back['a'];

	std::map<char, int> occuranceMap;
	occuranceMap['a'] = 10;

}