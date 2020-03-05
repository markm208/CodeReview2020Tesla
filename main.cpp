#include <iostream>
#include "mantissa.h"

using namespace std;

int main()
{
    cout<<"In-class Code Review"<<endl;
    
    int n, d;
    char number[] = "-123.456";
    mantissa(number, n, d);
    cout<< n << " over " << d <<endl;
    
    int n1, d1;
    char number1[] = ".0025";
    mantissa(number1, n1, d1);
    cout<< n1 << " over " << d1 <<endl;
    
    int n2, d2;
    char number2[] = "30";
    mantissa(number2, n2, d2);
    cout<< n2 << " over " << d2 <<endl;
    
    int n3, d3;
    char number3[] = "hello";
    mantissa(number3, n3, d3);
    cout<< n3 << " over " << d3 <<endl;

    return 0;
}
