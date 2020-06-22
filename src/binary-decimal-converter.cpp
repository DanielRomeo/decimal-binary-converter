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
using namespace std;

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
vector<int> integerToVectorConverter(int number){
	vector<int> result;
	int loop_number = numberOfDigitsInInteger(number);
	//string str = to_string(number);
	stringstream ss;
	ss << number;
	string str = ss.str();

	// add the digits one by one in the array
	for(unsigned i = 0; i < loop_number; i++){
		result.push_back(str[i]);
	}


	return result;
}

// takes in the array and the name we want to convert to
int decimalToBinary(){
	int number;
	vector<int> kv;
	int result;

	cout << "input the number you want to convert to Binary" << endl;
	cin >> number;
//	cout << number;
	kv = integerToVectorConverter(number);

	// convert vector to integer:
//	for (int d : kv)  {
//	    result = result * 10 + d;
//	}
//	cout << "a" ;
	return kv[1];
}

int binaryToDecimal(){
	return 4;
}

int main() {

	/*Goal is to let user select what they want to the numbers*/
	//vector <int> binaryNumbers;
	char input;
	int output;

	cout << "(A) Convert binary to decimal \n(B) Convert decimal to binary" << endl;
	cin >> input;
	if(input == 'a' || input =='A'){
		output = binaryToDecimal();
	}else if(input == 'b' || input == 'B'){
		output = decimalToBinary();
	}

	cout << output << endl;

	return 0;
}








