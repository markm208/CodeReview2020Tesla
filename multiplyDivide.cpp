#include <iostream>
#include "MultiplyDivide.h"

using namespace std;

bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
	bool retVal = false;

	int num1 = (c1 * d1) + n1; //calculates numerator 1
	int num2 = (c2 * d2) + n2; //calculates numerator 2
	int num3 = num1 * num2; //calculates the result numerator

	int finalDenominator = d1 * d2; //calculates the resulting denominator of the mantissa
	int finalCharacteristic = (num3 / finalDenominator); //calculates the resulting characteristic
	int finalMantissa = (num3 - (finalCharacteristic * finalDenominator)); //calculates the resulting mantissa

	int i = 0;

	/*takes each digit from finalCharacteristic
	converts it to a char
	adds it to the result array*/
	int temp = finalCharacteristic;
	while (i < len && temp > 0)
	{
		int digit = temp % 10; //get digit
		char charDigit = (char)(digit + '0'); //convert to char
		result[i] = charDigit;
		i++; 
		temp /= 10; //remove current digit
	}

	reverseCharArr(result, 0, i - 1); //digits were pushed to back of array so result must be reversed
	retVal = checkEqual(result, finalCharacteristic, i); //check if at least the characteristic was stored in result
	result[i] = '.'; //and decimal point
	i++;
	int startOfNum = i; //preverses current value of i to be used later

	/*takes each digit from finalNumerator
	converts it to a char
	adds it to result array*/
	while (i < len && finalMantissa > 0)
	{
		int digit = finalMantissa % 10; //get digit
		char charDigit = (char)(digit + '0'); //convert to char
		result[i] = charDigit;
		i++;
		finalMantissa /= 10; //remove current digit
	}

	reverseCharArr(result, startOfNum, i - 1); //reverses the values in result after the '.'
	result[i] = '/0';
	
	return retVal;
}

bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
	bool retVal = false;

	int num1 = (c1 * d1) + n1; //calculates numerator 1
	int num2 = (c2 * d2) + n2; //calculates numerator 2
	int improperNum = num1 * d2; //cross multiply for numerator
	int improperDen = d1 * num2; //cross multiply for denominator

	int finalCharacteristic = improperNum / improperDen; //get final characteristic
	int finalMantissa = ((improperNum % improperDen) * 10000 / improperDen); //get final mantissa

	int i = 0;

	/*takes each digit from finalCharacteristic
	converts it to a char
	adds it to the result array*/
	int temp = finalCharacteristic;
	while (i < len && temp > 0)
	{
		int digit = temp % 10; //get digit
		char charDigit = (char)(digit + '0'); //convert to char
		result[i] = charDigit;
		i++;
		temp /= 10; //remove current digit
	}

	reverseCharArr(result, 0, i - 1); //digits were pushed to back of array so result must be reversed
	retVal = checkEqual(result, finalCharacteristic, i); //check if at least the characteristic was stored in result
	result[i] = '.'; //and decimal point
	i++;
	int startOfNum = i; //preverses current value of i to be used later

	/*takes each digit from finalNumerator
	converts it to a char
	adds it to result array*/
	while (i < len && finalMantissa > 0)
	{
		int digit = finalMantissa % 10; //get digit
		char charDigit = (char)(digit + '0'); //convert to char
		result[i] = charDigit;
		i++;
		finalMantissa /= 10; //remove current digit
	}

	reverseCharArr(result, startOfNum, i - 1); //reverses the values in result after the '.'
	result[i] = '/0';

	return retVal;
}

//reverses a elements in a given character array from given start position to given end position
void reverseCharArr(char arr[], int start, int end)
{
	while (start < end)
	{
		char temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

//compares each member of a char array is equal to each digit of an int
bool checkEqual(char arr[], int n, int len)
{
	for (int i = len-1; i >= 0; i--)
	{
		if (arr[i] != char((n % 10) + '0'))
			return false;
		n /= 10;
	}
	return true;
}