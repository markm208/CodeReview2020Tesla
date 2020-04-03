//
//  add_subtract.cpp
//  add_subtract
//
//  Created by Brad Dodds on 3/5/20.
//  Copyright © 2020 Brad Dodds. All rights reserved.
//

#include "add_subtract.h"
#include <iostream>

using namespace std;

/*----HELPER FUNCTIONS----*/

//creates improper fraction and returns numerator
int improperFractionNumerator (int c1, int n1, int d1) {
    int temp = 0;
    temp = c1 * d1;
    if(temp < 0) {
        temp = temp - n1;
        return temp;
    }
    else
        return temp + n1;
}

//common denominator helper function
int commonDenom (int d1, int d2) {
        return d1 * d2;
}

long long moveDecimal(long long numerator, int digitsLeft, int commonDenom) {
    unsigned long long returnNum = 0;
    long long temp = 1;
    for(int i = 0; i < digitsLeft-1; i++) {
        temp = temp * 10;
    }
    //reduces size of number for precision
    if(numerator % commonDenom == 0){
        numerator = numerator / commonDenom;
        returnNum = numerator * temp;
    }
    else
        returnNum = (temp * numerator) / commonDenom;
    
    return returnNum;
}



//--------------------------------------------------------------------------------
bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len) {
    bool retVal = false;
    //creates sum of numerators with helper function
    int num1 = improperFractionNumerator(c1, n1, d1) * d2;
    int num2 = improperFractionNumerator(c2, n2, d2) * d1;
    long long numeratorSum = num1 + num2;
    //creates a common denominator with helper function
    int common_denom = commonDenom(d1, d2);
    //creates whole number without decimals
    int wholeNum = int(numeratorSum / common_denom);
    long long temp = wholeNum;//holds wholeNum
    int index = 0;
    
    if(temp == 0) {
        result[0] = char('0');
        index++;
    }
    //increments index variable until '.'
    while(temp != 0) {
        index++;
        temp = temp / 10;
    }
    
    //+ 2 to take '.' and '\0' into consideration
    if(index + 2 < len) {
        temp = wholeNum;    //reassign temp
        
        if(numeratorSum < 0) {
            result[0] = '-';
            index = 1;
        }
        
        //adds whole number from right to left starting at index
        while(temp != 0) {
            int i = 1;
            unsigned int inputNum = temp % 10;//adds last digit at a time if > 10
            result[index - i] = char('0' + inputNum);
            temp = temp / 10;
            i++;
        }
        result[index] = '.';
        index++;
        
        //counter is at index of decimal point
        int digitsLeft = len - index;
        //moves decimal to the right for the amount of digits left
        temp = moveDecimal(numeratorSum, digitsLeft, common_denom);
        if(temp < 0)
            temp = temp * -1;
        //load decimals into c string from the right to left
        for(int i = len - 1; i > index; i--) {
            int decimal = temp % 10;
            result[i - 1] = char('0' + decimal);
            temp = temp / 10;
        }
        result[len - 1] = '\0';
        retVal = true;
    }
    return retVal;
}

//-----------------------------------------------------------------------------------
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len) {
    bool returnVal = false;
    int num1 = improperFractionNumerator(c1, n1, d1) * d2;
    int num2 = improperFractionNumerator(c2, n2, d2) * d1;
    long long numeratorDifference = num1 - num2;
    //creates common denominator
    int common_denom = commonDenom(d1, d2);
    //creates whole number without decimals
    int wholeNum = int(numeratorDifference / common_denom);
    long long temp = wholeNum;
    int index = 0;
    
    if(temp == 0) {
        result[0] = char('0');
        index++;
    }
    //increments index variable until '.'
    while(temp != 0) {
        index++;
        temp = temp / 10;
    }
    
    if(index + 2 < len) {
        temp = wholeNum;
        
        //adds nugative sign and reassigns index
        if(numeratorDifference < 0) {
            result[0] = '-';
            index = 1;
        }
        
        //adds whole number from right to left starting at index
        while(temp != 0) {
            int i = 1;
            unsigned int inputNum = temp % 10;//adds last digit at a time if > 10
            result[index - i] = char('0' + inputNum);
            temp = temp / 10;
            i++;
        }

        result[index] = '.';
        index++;
        
        int digitsLeft = len - index;
        temp = moveDecimal(numeratorDifference, digitsLeft, common_denom);
        if(temp < 0)
            temp = temp * -1;
        
        //load decimals into c string from the right to left
        for(int i = len - 1; i > index; i--) {
            int decimal = temp % 10;
            result[i - 1] = char('0' + decimal);
            temp = temp / 10;
        }
        result[len - 1] = '\0';
        returnVal = true;
    }
    return returnVal;
}
