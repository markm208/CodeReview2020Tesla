#include <iostream>
#include <ctype.h>
#include "mantissa.h"

using namespace std;
//bool mantissa(char numString[], int& numerator, int& denominator);

bool mantissa(const char numString[], int& numerator, int& denominator)
{
    int length = 0 ;
    bool hasDecimal = false;
    int decimalPos = NULL;
    denominator = 1;
    numerator = 0;
    
    if(isValid(numString) == false ||hasDigits(numString)==false)
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
        denominator = 10;
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
    
    //turns nums[] into an int
    
    numerator = makeInt(nums);
    
    
    int numeratorCopy = numerator;
    int numeratorLength = 1;
    if (numerator > 0)
    {
        // we count how many times it can be divided by 10:
        // (how many times we can cut off the last digit until we end up with 0)
        for ( numeratorLength = 0; numeratorCopy > 0; numeratorLength++)
        {
            numeratorCopy = numeratorCopy / 10;
        }
    }
    
    //calculates denominator based on the number of digits after the decimal
    if(nums[0] == '0' && numeratorLength > 0)
    {
        for(int i = 0;i < iterator; i++)
        {
            denominator = denominator * 10;
        }
    }
    else
    {
        for(int i = 0 ;i < numeratorLength; i++)
        {
            denominator = denominator * 10;
        }
        
    }
    
    if(isNegative(numString,decimalPos))
    {
        numerator = numerator * -1;
    }
    

    return true;
}


//Helper functions

//checks if passed in numstring is valid entry
bool isValid(const char numString[])
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
//mahoney recommends removing one of the isDigit functions as it is
//used in both caracteristic and mantissa and created a duplicate symbol error
/*bool isDigit(char c)
{
    if(c >= 48 && c <= 57)
    {
        return true;
        
    }
    else
    {
        return false;
    }
    
}*/

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
int makeInt(const char numString[])
{
    int result = 0;
    
    
    for(int i = 0 ;numString[i] != NULL; i++)
    {
        if(numString[i] != '0' && isDigit(numString[i]))
        {
            result = result*10 + numString[i] - '0';
        }
        else
        {
            result = result + 0;
        }
    }
    
        return result;
    
}

//checks to see if a character is a number
bool isNegative(const char numString[],int decPos)
{
   
     for(int i = 0 ;numString[i] != NULL; i++)
     {
        if(numString[i]== '-')
        {
           if(numString[i + 1] == '0'& numString[i + 2] == '.')
           {
               return true;

           }
            else if( numString[i + 1] == '.')
            {
                 return true;
            }
        }
     }
    
 
    
    return false;
    
}

//checks to se if numstring has numbers in it
bool hasDigits(const char numString[])
{
     for(int i = 0 ;numString[i] != NULL; i++)
     {
         if(numString[i]  >= 48 && numString[i]  <= 57)
         {
             return true;
         }
     }
   
        return false;
    
    
}
