#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>

void DutchFlagPartition(int pivotIndex, std::vector<int> inputVector){

	int pivot = inputVector[pivotIndex];

	int smallerIndex = 0;
	int equalIndex = 0;
	int largerIndex = inputVector.size();

	/*
	There are 4 groups:
	Smaller than [0, smallerIndex-1]
	equal to [smallerIndex, equalIndex-1]
	larger than [largerIndex, size()-1]

	unprocessed [equalIndex, largerIndex]	this group reaches 0 once we are done. 
	*/

	while (equalIndex < largerIndex)
	{
		if (inputVector[equalIndex] < pivot){
			std::swap(inputVector[equalIndex], inputVector[smallerIndex]);
			equalIndex++;
			smallerIndex++;
		}
		else if (inputVector[equalIndex] == pivot){
			equalIndex++;
		}
		else{
			std::swap(inputVector[equalIndex], inputVector[largerIndex]);
			largerIndex--;
		}
	}
	
}

int dog(int a, int b) {

}

int foo(){

}

int bar(){

}

void test(){
	int mydog = dog(foo(), bar());
}