#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>


/*
	This file currently includes:
	Merge Sort: 
		std::vector<int> mergeSort(std::vector<int> targetVector);
	Insertion Sort:
		std::vector<int> insertionSort(std::vector<int> targetVector);
*/


//Forward Declaration
std::vector<int> mergeSort(std::vector<int> targetVector);
std::vector<int> mergeVectors(std::vector<int> leftVector, std::vector<int> rightVector);
std::vector<int> insertionSort(std::vector<int> targetVector);

std::vector<int> mergeSort(std::vector<int> targetVector){
	//base case, empty vector, sorted by definition. 
	if (targetVector.size() <= 1){
		return targetVector;
	}

	//recursive case
	//divide into two vectors, left and right
	std::vector<int> left, right;
	int middle = targetVector.size() / 2;
	for (int i = 0; i < middle; i++){
		left.emplace_back(targetVector[i]);
	}
	for (unsigned int i = middle; i < targetVector.size(); i++){
		right.emplace_back(targetVector[i]);
	}

	//sort each individual vector
	left = mergeSort(left);
	right = mergeSort(right);

	return mergeVectors(left, right);
}

std::vector<int> mergeVectors(std::vector<int> leftVector, std::vector<int> rightVector){
	std::vector<int> resultVector;
	while (!leftVector.empty() && !rightVector.empty())
	{
		if (leftVector[0] <= rightVector[0])
		{
			resultVector.emplace_back(leftVector[0]);
			leftVector.erase(leftVector.begin(), leftVector.begin() + 1);
		}
		else
		{
			resultVector.emplace_back(rightVector[0]);
			rightVector.erase(rightVector.begin(), rightVector.begin() + 1);
		}
	}

	while (!leftVector.empty())
	{
		resultVector.emplace_back(leftVector[0]);
		leftVector.erase(leftVector.begin(), leftVector.begin() + 1);
	}

	while (!rightVector.empty())
	{
		resultVector.emplace_back(rightVector[0]);
		rightVector.erase(rightVector.begin(), rightVector.begin() + 1);
	}

	return resultVector;
}


std::vector<int> insertionSort(std::vector<int> targetVector){
	int position;

	for (unsigned int i = 0; i < targetVector.size(); i++){
		position = i;
		//starting with the value at i, 
		//while it is still smaller than the value in front of it, swap it with the position in front of it.
		//keep going until the value in front of it is no longer larger than itself.
		while (position > 0 && targetVector[position - 1] > targetVector[position]){
			std::swap(targetVector[position], targetVector[position - 1]);
			position--;
		}
	}

	return targetVector;
}