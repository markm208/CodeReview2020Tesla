//
//  mantissa.h
//  code review 2
//
//  Created by Morgan Robinson on 3/5/20.
//  Copyright © 2020 Morgan Robinson. All rights reserved.
//
#define mantissa_h
bool mantissa(const char numString[], int& numerator, int& denominator);
bool isValid(char numString[]);
bool isDigit(char c);
bool isSpace(char s);
int makeInt(char numString[]);
bool isNegative(char numString[],int decPos);
bool hasDigits(char numString[]);


