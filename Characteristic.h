#pragma once
class Characteristic
{
public:
	bool characteristic(char numString[], int& c);

private:
	// conversion helper functions
	bool isDigit(char ch);
	bool isNumValid(char numString[]);
	bool hasCharacteristic(char numString[]); // checks if any characteristic entered ex: -.123
	bool isNegative(char numString[]); // negative nums with no characteristic must be handled by mantissa
	bool findIn(char numString[], char c);

	int findFirstIndexOf(char numString[], char c);
	int pow(int base, int power);
	int getCStringSize(char string[]);
};

