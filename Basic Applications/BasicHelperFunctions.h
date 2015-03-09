#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <string>


/*
This file currently includes:
	stringToInt(string parseThis)
*/

int convertStringToInt(std::string parseThis){
	int value = std::stoi(parseThis);
	int value_a = atoi(parseThis.c_str());
	/*
	stoi means string to int
	the difference between stoi and atoi is that atoi uses c strings, thus is more flexible but require more work to use. 
	atoi is also part of the c library and thus does not need std::
	*/
	return value;
}

float convertStringToFloat(std::string parseThis){
	float value = std::stof(parseThis);
	float value_a = atof(parseThis.c_str());
	return value;
}

template<typename T>
T myFunction(T parameter){
	return parameter;
}

template<>
std::string myFunction(std::string parameter){
	std::string tempString;
	tempString = "the value was a string, and contained: " + parameter;
	return tempString;
}