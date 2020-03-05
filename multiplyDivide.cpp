#include <iostream>
#include "multiplyDivide.h"

using namespace std; 

bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
	int num1 = (c1 * d1) + n1; //calculates numerator 1
	int num2 = (c2 * d2) + n2; //calculates numerator 2
	int num3 = num1 * num2; //calculates the result numerator

	int finalDenominator = d1 * d2; //calculates the resulting denominator of the mantissa
	int finalCharacteristic = (num3 / finalDenominator); //calculates the resulting characteristic
	int finalNumerator = (num3 - (finalCharacteristic * finalDenominator)); //calculates the resulting numerator of the mantissa

	int i = 0;

	while (finalCharacteristic > 0)
	{
		int digit = finalCharacteristic % 10;
		char charDigit = (char)(digit + '0');
		result[i] = charDigit;
		i++;
		finalCharacteristic /= 10;
	}

	reverseCharArr(result, 0, i - 1);
	result[i] = '.';
	i++;

	int startStartOfNum = i;
	while (finalNumerator > 0)
	{
		int digit = finalNumerator % 10;
		char charDigit = (char)(digit + '0');
		result[i] = charDigit;
		i++;
		finalNumerator /= 10;
	}

	reverseCharArr(result, startStartOfNum, i - 1);
	result[i] = '/0';

	if (result[0] != ' ')
		return true;
	else
		return false;
}

bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
	int num1 = (c1 * d1) + n1; //calculates numerator 1
	int num2 = (c2 * d2) + n2; //calculates numerator 2
	int finalNum = num1 * d2;
	int finalDen = d1 * num2;

	int i = 0;

	while (finalNum > 0 && i < len)
	{
		int digit = finalNum % 10;
		char charDigit = (char)(digit + '0');
		result[i] = charDigit;
		i++;
		finalNum /= 10;
	}

	reverseCharArr(result, 0, i - 1);
	result[i] = '.';
	i++;

	int startStartOfNum = i;
	while (finalDen > 0 && i < len)
	{
		int digit = finalDen % 10;
		char charDigit = (char)(digit + '0');
		result[i] = charDigit;
		i++;
		finalDen /= 10;
	}

	if (result[0] != ' ')
		return true;
	else
		return false;
}

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