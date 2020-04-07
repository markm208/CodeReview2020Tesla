#ifndef Characteristic_h
#define Characteristic_h

#pragma once

bool characteristic(const char numString[], int& c);

// conversion helper functions
bool isDigit(char ch);
bool isNumValid(const char numString[]);
bool hasCharacteristic(const char numString[]); // checks if any characteristic entered ex: -.123
bool isNegative(const char numString[]); // negative nums with no characteristic must be handled by mantissa
bool findIn(const char numString[], char c);
int findFirstIndexOf(const char numString[], char c);
int pow(int base, int power);
int getCStringSize(const char string[]);

#endif Characteristic_h