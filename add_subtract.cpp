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
    temp = c1 * d1 + n1;
    return temp;
}

//common denominator helper function
int commonDenom (int d1, int d2) {
    if(d1 == d2)                //if denominators are the same return d1
        return d1;
    else                        //else multiply for lowest common denominator
        return d1 * d2;
}

int moveDecimal(long numerator, int digitsLeft, int commonDenom) {
    int returnNum = 0;
    int temp = 1;
    for(int i = 0; i < digitsLeft; i++) {
        numerator = numerator * 10;
    }
    returnNum = int(numerator / commonDenom);
    //for and while loops check returned size
    for(int i = 0; i < digitsLeft - 0; i++) {
        temp = temp * 10;
    }
    while(returnNum / temp >= 1)
        returnNum = returnNum / 10;
    
    return returnNum;
}



//--------------------------------------------------------------------------------
bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len) {
    bool retVal = false;
    
    //creates sum of numerators with helper function
    int num1 = improperFractionNumerator(c1, n1, d1) * d2;
    int num2 = improperFractionNumerator(c2, n2, d2) * d1;
    int numeratorSum = num1 + num2;
    
    //creates a common denominator with helper function
    int common_denom = commonDenom(d1, d2);
    
    //creates whole number without decimals
    int wholeNum = numeratorSum / common_denom;
    
    int temp = wholeNum;//holds wholeNum
    int index = 0;
    
    //increments index of '.'
    while(temp != 0) {
        index++;
        temp = temp / 10;
    }
    
    //starting c string off with '0','.' and incrementing
    //index if answer will be < 1
    if(index == 0) {
        result[0] = '0';
        result[1] = '.';
        index++;
    }
    
    //+ 2 to take '.' and '\0' into consideration
    if(index + 2 < len) {
        temp = wholeNum;    //reassign temp
        
        //adds whole number from right to left starting at index
        for(int i = index; i > 0; i--) {
            int inputNum = temp % 10;//adds last digit at a time if > 10
            result[i - 1] = char('0' + inputNum);
            temp = temp / 10;
        }
        result[index] = '.';
        index++;
        
        //counter is at index of decimal point
        int digitsLeft = len - index;
        //moves decimal to the right for the amount of digits left
        temp = moveDecimal(numeratorSum, digitsLeft, common_denom);
        
        //load decimals into c string from the right to left
        for(int i = len - 1; i > index; i--) {
            int decimal = temp % 10;
            result[i - 1] = char('0' + decimal);
            temp = temp / 10;
        }
        retVal = true;
    }
    return retVal;
}

//-----------------------------------------------------------------------------------
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len) {
    bool returnVal = false;
    int num1 = improperFractionNumerator(c1, n1, d1) * d2;
    int num2 = improperFractionNumerator(c2, n2, d2) * d1;
    int numeratorDifference = num1 - num2;
    //creates common denominator
    int common_denom = commonDenom(d1, d2);
    
    //creates whole number without decimals
    int wholeNum = numeratorDifference / common_denom;
    int temp = wholeNum;
    int index = 0;
    
    //increments index of '.'
    while(temp != 0) {
        index++;
        temp = temp / 10;
    }
    
    //starting c string off with '0','.' and incrementing
    //index if answer will be 0 < 1
    if(index == 0) {
        result[0] = '0';
        result[1] = '.';
        index = index + 2;
    }

    if(index < len) {
        temp = wholeNum;
        
        //adds nugative sign and reassigns index
        if(numeratorDifference < 0) {
            numeratorDifference = numeratorDifference * -1;
            result[0] = '-';
            index = 1;
            if(temp == 0) {     //add '0' and '.' after negative sign
                result[1] = '0';
                result[2] = '.';
                index = index + 2;
            }
        }
        else {
            //adds whole number from right to left starting at index
            for(int i = index; i > 0; i--) {
                int inputNum = temp % 10;//adds last digit at a time if > 10
                result[i - 1] = char('0' + inputNum);
                temp = temp / 10;
            }
            result[index] = '.';
            index++;
        }
        
        int digitsLeft = len - index;
        int temp = moveDecimal(numeratorDifference, digitsLeft, common_denom);

        //load decimals into c string from the right to left
        for(int i = len - 1; i > index; i--) {
            int decimal = temp % 10;
            result[i - 1] = char('0' + decimal);
            temp = temp / 10;
        }
        returnVal = true;
    }
    return returnVal;
}