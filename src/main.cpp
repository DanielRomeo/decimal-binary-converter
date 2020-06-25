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

/* a little reminder of things*/
// std::cout << "Type of digit is : " << typeid(name).name() << std::endl;

/*  loop through vector
for(auto i = result.begin() ; i < result.end(); i++){
	std::cout << "its "<< *i;
}*/


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
	std::stringstream ss;
	ss << number;
	std::string str = ss.str();
	std::cout << str << std::endl;

	for(int i = 0; i < str.size(); i++){
		// convert an integer string to an int
		digit = str[i] - '0';
		result.push_back(digit); 
	}
	return result;
}

int vectorToIntegerConverter(std::vector<int> vecNumber){
	// reverse(v.begin(), v.end());
    int decimal = 1;
    int total = 0;
    for (auto& it : vecNumber)
    {
        total += it * decimal;
        decimal *= 10;
    }
    return total;
}

// takes in the array and the name we want to convert to
int decimalToBinary(){
	int number;
	int result = 0;
	int base = 2;
	int newNumber ;
	int data ;
	std::vector<int> bin;
	int newInteger;

	std::cout << "input the number you want to convert to Binary" << std::endl;
	std::cin >> number;

	newNumber = number;
	while(newNumber > 0){

		data = number % 2;

		newNumber = number / 2;
		if(data > 0){
			bin.push_back(1);
		}else{
			bin.push_back(0);
		}
		number = newNumber;
	}

	newInteger = vectorToIntegerConverter(bin);

	return newInteger;
}

int binaryToDecimal(){
	int number;
	int vecNumber;
	int base = 2;
	int thePower;
	int digit ;
	int sum =0;
	std::cout << "input the number you want to convert to Decimal" << std::endl;
	std::cin >> number;

	// convert number to a vector
	//vecNumber = integerToVectorConverter(number);


	// convert a number into a string so that we can loop through it.
	std::stringstream ss;
	ss << number;
	std::string str = ss.str();

	thePower = str.size();
	
	// loop through vector and add together values:
	for (int i = 0; i < str.size(); i++)
	{
		thePower--;
		std::cout <<"\n"<< i << " base :" <<base << " power : " << thePower <<". The digit is " << digit;

		digit = str[i] - '0';		
		digit = digit *pow(base, thePower) ;
		
		sum += digit;
		
	}


	return sum;
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

	std::cout <<"\nAnswer : " <<  output << std::endl;

	return 0;
}








