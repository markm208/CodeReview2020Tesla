//
//  mantissa.h
//  code review 2
//
//  Created by Morgan Robinson on 3/5/20.
//  Copyright © 2020 Morgan Robinson. All rights reserved.
//
#define mantissa_h
bool mantissa( const char numString[], int& numerator, int& denominator);
bool isValid(const char numString[]);
bool isSpace(char s);
int makeInt(const char numString[]);
bool isNegative(const char numString[],int decPos);
bool hasDigits(const char numString[]);
bool onlyZeros(const char numString[]);


