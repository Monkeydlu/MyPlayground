// Basic Applications.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

#include "PokerDeck.h"
#include "MySortFunctions.h"
#include "MyLinkedList.h"
#include "Chapter_14.h"
#include "BasicHelperFunctions.h"



int main(int argc, _TCHAR* argv[])
{
	/*
	std::cout << "Hello world!" << std::endl;
	std::cout << "What is your name?" << std::endl;
	std::string nameInput = "";
	std::cin >> nameInput; 
	std::cin.get();
	std::cout << "It's nice to meet you " << nameInput << std::endl;
	*/

	
	//testLinkedList();	//tests the linked list. Function is in MyLinkedList.h
	//findBestHand(5); //test the PokerDeck Class.
	//chapter14_1();
	chapter14_2();

	std::cin.get();
	return 0;
}

void testSort(){
	std::vector<int> targetVector = { 3, 5, 1, 2, 2, 4, 1 };

	//std::vector<int> resultVector = insertionSort(targetVector);

	std::vector<int> resultVector = mergeSort(targetVector);

	for (unsigned int i = 0; i < resultVector.size(); i++){
		std::cout << targetVector[i] << "\t" << resultVector[i] << std::endl;
	}

}