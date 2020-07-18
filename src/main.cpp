//============================================================================
// Name        : binary-decimal-converter.cpp
// Author      : daniel
// Version     :
// Copyright   : Your copyright notice
// Description : A basic number converter application
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
#include <cctype>
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
// std::cout << "Type of digit is : " << typeid(a).name() << std::endl;

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

// std::vector<string> vectorToStringConverter(std::vectore<int> vec){

// }

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

// -------------------------------------------------------------------------------------------

std::string decimalToHex(){
	/*	
		i have a vector of strings...
		-> convert vector to a string
	*/

	int i = 0;
	float number;
	int newNumber;
	float base = 16.00;
	int mainer;
	float answer = 1.00;
	// float remainder;
	float decimal ;
	int digit;
	int sum = 0;
	std::vector<std::string> bin;
	std::string charector;
	std::string sDigit ;
	std::string result;

	std::cout << "input the number you want to convert to hexidecimal" << std::endl;
	std::cin >> number;

	mainer = 1;
	answer = number / base;
	while(mainer !=0){
		mainer = (int)answer;
		// std::cout << mainer << "<- ";
		decimal = answer - mainer;
		digit = base * decimal;

		// convert digit to string:
		sDigit = std::to_string(digit);
		//Hex adjustments-- convert numbers to Alphabets
		// std::cout << " digit: " << sDigit << " ";
		if(sDigit == "10"){
			charector = "A";
			bin.push_back("A");
			// continue;
		}else if(sDigit == "11"){
			charector = "B";
			bin.push_back("B");
			// continue;
		}else if(sDigit == "12"){
			charector = "C";
			bin.push_back("C");
			// continue;
		}else if(sDigit == "13"){
			charector = "D";
			bin.push_back("D");
			// continue;
		}else if(sDigit == "14"){
			charector = "E";
			bin.push_back("E");
			// continue;
		}else if(sDigit == "15"){
			charector = "F";
			bin.push_back("F");
			// continue;
		}else{
			bin.push_back(sDigit);	
		}

		number = mainer;	
		answer = number / base;

	}

	// reverse a vector:
	std::reverse(std::begin(bin), std::end(bin));

	//convert vector to a string:
	for(const auto &piece : bin){
		result += piece;
	}
	return result;
}

/*-----------------------------*/

int decimalToOct(){
	int i = 0;
	float number;
	int newNumber;
	float base = 8.00;
	int mainer;
	float answer = 0.00;
	// float remainder;
	float decimal ;
	int digit;
	int sum = 0;
	std::vector<int> bin;

	std::cout << "input the number you want to convert to Octal" << std::endl;
	std::cin >> number;

	//newNumber = number;
	answer = number / base;
	while(answer >0){
		
		
		/*may need to figure out why answer never goes below zero.*/
		if(answer == 0){
			i++;
		}
		if(i == 5){
			break;
		}

		/*get the mianer and the decimal*/ //1: turn it into an integer:
		mainer = (int)answer;
		decimal = answer - mainer;
		digit = base * decimal;
		bin.push_back(digit);
		number = answer;	
		answer = number / base;
	}

	newNumber = vectorToIntegerConverter(bin);
	return newNumber;	
}

/*hexidecimal to octal*/
int hexToDecimal(){
	// int i = 0;
	std::string number;
	int thePower;
	int base = 16;

	float answer = 0.00;
	// float remainder;

	int digit;
	int sum = 0;
	std::vector<std::string> bin;

	std::cout << "input the Hex number you want to convert to decimal" << std::endl;
	std::cin >> number;

	// loop through the string:
	for(std::string::size_type i = 0; i < number.size(); ++i){

		// convert a number[i] into a string 
		std::stringstream ss;
		ss << number[i];
		std::string str = ss.str();

		if(str == "a" || str == "A"){
			bin.push_back("10");
			continue;			
		}else if(str == "b" || str == "B"){
			bin.push_back("11");
			continue;			
		}else if(str == "c" || str == "C"){
			bin.push_back("12");
			continue;			
		}else if(str == "d" || str == "D"){
			bin.push_back("13");
			continue;			
		}else if(str == "e" || str == "E"){
			bin.push_back("14");
			continue;			
		}else if(str == "f" || str == "F"){
			bin.push_back("15");
			continue;			
		}
		bin.push_back(str);
	}

	std::string ab;
	// now .. i have a vector of integers:
	// loop through vector:


	thePower = bin.size();
	for (std::string::size_type i = 0; i < bin.size(); ++i)
	{
		std::stringstream ss;
		ss << bin[i];
		std::string str2 = ss.str();

		digit = str2[i] - '0';


		//std::cout << digit;
		thePower--;
		digit = digit *pow(base, thePower) ;
		sum += digit;
	}

	return sum;

}

/*octal to decimal*/
int octToDecimal(){

}



// -------------------------------------------------------------------------------------------

int main() {
	char input;
	auto output= 0.00;
	std::string outta;
	std::cout << "(A) Convert binary to decimal \n---------------------- \n(B) Convert decimal to binary\n(C) Convert decimal to hexidecimal \n(D) Convert decimal to Octal" << std::endl;
	std::cout << "(E) Convert hexidecimal to decimal" << std::endl;
	std::cout << "(F) Convert octal to decimal" << std::endl;

	std::cin >> input;
	if(input == 'a' || input =='A'){
		output = binaryToDecimal();
	}else if(input == 'b' || input == 'B'){
		output = decimalToBinary();
	}else if(input == 'c' || input == 'C'){
		outta = decimalToHex();
	}else if(input == 'd' || input == 'D'){
		output = decimalToOct();
	}else if(input == 'e' || input == 'E'){
		output = hexToDecimal();
	}else if(input == 'f' || input == 'F'){
		output = octToDecimal();
	}

	if(output = 0.00){
		std::cout << outta;
	}else{
		std::cout <<"\nAnswer : " <<  output << std::endl;	
	}
	

	return 0;
}








