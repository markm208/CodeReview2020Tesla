#include <iostream>
#include <ctype.h>
#include "mantissa.h"

using namespace std;
//bool mantissa(char numString[], int& numerator, int& denominator);

bool mantissa(char numString[], int& numerator, int& denominator)
{
    int length = 0 ;
    bool hasDecimal = false;
    int decimalPos = NULL;
    denominator = 10;
    numerator = 0;
    
    if(isValid(numString) == false)
    {
        return false;
    }
    
    
    //calculating the length of numString and position of decimal if there is one
    while(numString[length] != NULL)
    {
            if(numString[length] == '.')
            {
                hasDecimal = true;
                decimalPos = length;
            }
            
        length++;
    }
   
    //if there is no decimal point in the string then numerator = 0 and denominator = 10
    if(hasDecimal == false)
    {
      return true;
    }
    
    char nums[0];//array for all numbers after decimal point
    int iterator = 0;//will hold the length of nums[]
    
    //fills nums[]
    for (int i = decimalPos; i < length; i++)
    {
        if(isDigit(numString[i]))
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
    numerator = makeInt(nums);
    

    return true;
}


//Helper functions

//checks if passed in numstring is valid entry
bool isValid(char numString[])
{
    int iterator = 0 ;
    while(numString[iterator] != NULL)
    {
        //returns false if any invalid character is found
        if(isDigit(numString[iterator])== false && isSpace(numString[iterator]) == false)
        {
            if(numString[iterator] != '.')
            {
                 if (numString[iterator] != '-' && numString[iterator] != '+')
                {
                    return false;
                }
            }
           
        }
        
        iterator++;
    }
    return true;
}

//checks to see if a character is a number
bool isDigit(char c)
{
    if(c >= 48 && c <= 57)
    {
        return true;
        
    }
    else
    {
        return false;
    }
    
}

//checks to see if a charcater is a space
bool isSpace(char s)
{
    if(s == 32)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//turns char into an int
int makeInt(char numString[])
{
    int result = 0;
    
    for(int i = 0 ;numString[i] != NULL; i++)
    {
        result = result*10 + numString[i] - '0';
    }
    
        return result;
    
}
