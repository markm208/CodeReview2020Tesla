//
//  mantissa.cpp
//  code review 2
//
//  Created by Morgan Robinson on 3/5/20.
//  Copyright © 2020 Morgan Robinson. All rights reserved.
//
#include <iostream>
#include <ctype.h>
#include "mantissa.h"

using namespace std;
bool mantissa(char numString[], int& numerator, int& denominator);

bool mantissa(char numString[], int& numerator, int& denominator)
{
    int length = 0 ;
    bool hasDecimal = false;
    int decimalPos = NULL;
    denominator = 10;
    numerator = 0;
    
    
    //calculating the length of numString and position of decimal if there is one
    while(numString[length] != NULL)
    {
        //returns false if any invalid character is found
        if(isdigit(numString[length])== false && isspace(numString[length]) == false)
        {
            if(numString[length] == '.')
            {
                hasDecimal = true;
                decimalPos = length;
            }
            else if (numString[length] != '-' && numString[length] != '+')
            {
                return false;
            }
        }
        
        length++;
    }
   
    //if there is no decimal point in the string then numerator = 0 and denominator = 10
    if(hasDecimal == false)
    {
      return true;
    }
    
    
    char nums[0];//array for all numbers after decimal point
    int iterator = 0;
    
    //fills nums[]
    for (int i = decimalPos; i < length; i++)
    {
        if(isdigit(numString[i]))
        {
            nums[iterator] = numString[i];
            iterator++;
        }
    }
    
    //calculates denominator based on the number of digits after the decimal
    for (int i = 0;i < iterator - 1; i++)
    {
        denominator = denominator * 10;
    }
    
    //turns nums[] into an int
    numerator = atoi(nums);

    return true;
}
