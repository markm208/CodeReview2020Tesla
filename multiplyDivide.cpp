#include <iostream>
#include "MultiplyDivide.h"

using namespace std;
bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
	bool retVal = false;

	//if either characteristic contains more digits than length return false
	if (countDigits(c1) > len - 1 || countDigits(c2) > len - 1)
		return false;
	//if either characteristic equals zero set result to zero
	if (c1 == 0 || c2 == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return true;
	}
	//test if either given characteristic is negative
	int i = 0;
	if (c1 < 0 || c2 < 0)
	{
		if (c1 < 0 && c2 < 0)
		{
			c1 *= -1;
			c2 *= -1;
		}
		else if (c1 < 0)
		{
			result[i] = '-';
			c1 *= -1;
			i++;
		}
		else
		{
			result[i] = '-';
			c2 *= -1;
			i++;
		}
	}

	int num1 = (c1 * d1) + n1; //calculates numerator 1
	int num2 = (c2 * d2) + n2; //calculates numerator 2

	int improperNum = num1 * num2; //calculates the result numerator
	int improperDen = d1 * d2; //calculates the resulting denominator of the mantissa

	//test if numerator equals 0 and set result to 0 if true
	if (improperNum == 0)
	{
		result[0] == '0';
		result[1] == '\0';
		return true;
	}

	long long finalCharacteristic = improperNum / improperDen; //get final characteristic
	long long tenPowLen = pow((long long)10, len - 3 - countDigits(finalCharacteristic));
	long long finalMantissa = ((long long)(improperNum % improperDen) * tenPowLen / improperDen); //get final mantissa

	/*takes each digit from finalCharacteristic
	converts it to a char
	adds it to the result array*/
	long long temp = finalCharacteristic; //finalCharacteristic will be needed later
	int startOfChar = i; //i won't necessarily be zero if there was a negative
	while (i < len - 1 && temp > 0)
	{
		int digit = temp % 10; //get digit
		char charDigit = digit + '0'; //convert to char
		result[i] = charDigit;
		i++;
		temp /= 10; //remove current digit
	}

	reverseCharArr(result, startOfChar, i - 1); //digits were pushed to back of array so result must be reversed
	retVal = checkEqual(result, finalCharacteristic, i); //check if at least the characteristic was stored in result

	//test if there is only 1 space left in array
	if (i == len - 1)
	{
		result[i] = '\0';
		return retVal;
	}
	//test if there would only be a 0 after decimal point
	if (finalMantissa == 0)
	{
		result[i] = '\0';
		return retVal;
	}

	result[i] = '.'; //add decimal point
	i++;
	int startOfNum = i; //preverses current value of i to be used later

	/*takes each digit from finalNumerator
	converts it to a char
	adds it to result array*/
	while (i < len - 1 && finalMantissa > 0)
	{
		int digit = finalMantissa % 10; //get digit
		char charDigit = (char)(digit + '0'); //convert to char
		result[i] = charDigit;
		i++;
		finalMantissa /= 10; //remove current digit
	}

	reverseCharArr(result, startOfNum, i - 1); //reverses the values in result after the '.'
	result[i] = '\0';

	return retVal;
}
//------------------------------------------------------------------------------------------
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
	bool retVal = false;

	//if either characteristic contains more digits than length return false
	if (countDigits(c1) > len - 1 || countDigits(c2) > len - 1)
		return false;
	//test if either given characteristic is negative
	int i = 0;
	if (c1 < 0 || c2 < 0)
	{
		if (c1 < 0 && c2 < 0)
		{
			c1 *= -1;
			c2 *= -1;
		}
		else if (c1 < 0)
		{
			result[i] = '-';
			c1 *= -1;
			i++;
		}
		else
		{
			result[i] = '-';
			c2 *= -1;
			i++;
		}
	}

	int num1 = (c1 * d1) + n1; //calculates numerator 1
	int num2 = (c2 * d2) + n2; //calculates numerator 2
	int improperNum = num1 * d2; //cross multiply for numerator
	int improperDen = d1 * num2; //cross multiply for denominator

	//test for divide by 0
	if (improperDen == 0)
	{
		return false;
	}
	//test if numerator equals 0 and set result to 0 if true
	if (improperNum == 0)
	{
		result[0] == '0';
		result[1] == '\0';
		return true;
	}

	long long finalCharacteristic = improperNum / improperDen; //get final characteristic
	long long tenPowLen = pow((long long)10, len - 3 - countDigits(finalCharacteristic));
	long long finalMantissa = ((long long)(improperNum % improperDen) * tenPowLen / improperDen); //get final mantissa

	/*takes each digit from finalCharacteristic
	converts it to a char
	adds it to the result array*/
	long long temp = finalCharacteristic; //finalCharacteristic will be needed later
	int startOfChar = i; //i won't necessarily be zero if there was a negative
	while (i < len - 1 && temp > 0)
	{
		int digit = temp % 10; //get digit
		char charDigit = digit + '0'; //convert to char
		result[i] = charDigit;
		i++;
		temp /= 10; //remove current digit
	}

	reverseCharArr(result, startOfChar, i - 1); //digits were pushed to back of array so result must be reversed
	retVal = checkEqual(result, finalCharacteristic, i); //check if at least the characteristic was stored in result

	//test if there is only 1 space left in array
	if (i == len - 1)
	{
		result[i] = '\0';
		return retVal;
	}
	//test if there would only be a 0 after decimal point
	if (finalMantissa == 0)
	{
		result[i] = '\0';
		return retVal;
	}

	result[i] = '.'; //add decimal point
	i++;
	int startOfNum = i; //preverses current value of i to be used later

	/*takes each digit from finalNumerator
	converts it to a char
	adds it to result array*/
	while (i < len - 1 && finalMantissa > 0)
	{
		int digit = finalMantissa % 10; //get digit
		char charDigit = digit + '0'; //convert to char
		result[i] = charDigit;
		i++;
		finalMantissa /= 10; //remove current digit
	}

	reverseCharArr(result, startOfNum, i - 1); //reverses the values in result after the '.'
	result[i] = '\0';

	return retVal;
}
//------------------------------------------------------------------------------------------
void reverseCharArr(char arr[], int start, int end)
{
	//reverses a elements in a given character array from given start position to given end position
	while (start < end)
	{
		char temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}
//------------------------------------------------------------------------------------------
bool checkEqual(char arr[], int n, int len)
{
	//compares each member of a char array is equal to each digit of an int
	for (int i = len - 1; i >= 0; i--)
	{
		if (arr[i] != char((n % 10) + '0'))
			return false;
		n /= 10;
	}
	return true;
}
//------------------------------------------------------------------------------------------
int countDigits(int n)
{
	//counts and returns number of digits in given integer
	int count = 0;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return count;
}
//------------------------------------------------------------------------------------------
long long pow(long long n, int p)
{
	//raises given number to given power, returns -1 if there is an issue
	if (p == 0)
		return 1;
	else if (p == 1)
		return n;
	else
	{
		long long origN = n;
		for (int i = 2; i <= p; i++)
		{
			n = n * origN;
		}
		return n;
	}
	return -1;
}