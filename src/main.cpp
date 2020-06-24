//============================================================================
// Name        : binary-decimal-converter.cpp
// Author      : daniel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <ios>
#include <sstream>
#include <typeinfo>
// using namespace std;

/*BINARY TO DECIMAL & VICE VERSA CONVERTA*/
int integerReverser(int num){
	int rev;

	 while(num > 0) {
	    rev = rev*10 + num%10;
	    num = num/10;
	 }
	 return rev;
}

// function that gets the number of digits in an integer:
int numberOfDigitsInInteger(int number){
	int result;
	unsigned int number_of_digits = 0;
	int n;
	do{
		++number_of_digits;
		n /= number;
	}while(n);

	return result;
}

// function that converts a number into an array
std::vector<int> integerToVectorConverter(int number){
	int digit;
	std::vector<int> result;
	//int loop_number = numberOfDigitsInInteger(number);
	//string str = to_string(number);
	std::stringstream ss;
	ss << number;
	std::string str = ss.str();

	std::cout << str << std::endl;
	//std::cout << "The string is :" << str;
	// add the digits one by one in the array
	for(int i = 0; i < str.size(); i++){
		// digit = std::stoi(str[i]);

		// need to convert this to a charector:
		digit = (int)str[i];
		std::cout << "Type of digit is : " << typeid(str[i]).name() << std::endl;
		std::cout << "---- " << digit << std::endl;
		result.push_back(digit); // problem here is that im storing strings into result instead of int's
		std::cout << "-- : " <<str[i] << std::endl;
	}

	for(auto i = result.begin() ; i < result.end(); i++){
		std::cout << "its "<< *i;
	}

	// std::cout << result << std::endl; 
	return result;

}

// takes in the array and the name we want to convert to
int decimalToBinary(){
	int number;
	
	int result = 0;

	std::cout << "input the number you want to convert to Binary" << std::endl;
	std::cin >> number;

	// kv is a vector:
	// kv = integerToVectorConverter(number);
	std::vector<int> kv(integerToVectorConverter(number));

	// lets see whats inside the vector:
	// for(auto i = kv.begin() ; i < kv.end(); i++){
	// 	std::cout << "its "<< *i;
	// }


	// convert vector to integer:
	// for (int d : kv)  {
	//     result = result * 10 + d;
	// }
		//std::cout << "a" ;
	return result;
}

int binaryToDecimal(){
	return 4;
}

int main() {

	/*Goal is to let user select what they want to the numbers*/
	//vector <int> binaryNumbers;
	char input;
	int output;

	std::cout << "(A) Convert binary to decimal \n(B) Convert decimal to binary" << std::endl;
	std::cin >> input;
	if(input == 'a' || input =='A'){
		output = binaryToDecimal();
	}else if(input == 'b' || input == 'B'){
		output = decimalToBinary();
	}

	std::cout <<"Final answer: " <<  output << std::endl;

	return 0;
}








