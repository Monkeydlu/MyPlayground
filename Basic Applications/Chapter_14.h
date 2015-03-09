#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

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