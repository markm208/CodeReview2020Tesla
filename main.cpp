#include <iostream>
#include"add_subtract.h"

using namespace std;

int main()
{

    int length = 10;
    char answer[length];
    int c1, n1, d1;
    int c2, n2, d2;
     
    c1 = 1;
    n1 = 1;
    d1 = 2;
     
    c2 = 1;
    n2 = 2;
    d2 = 3;
    
    //if the C string could hold at least the characteristic
       if(add(c1, n1, d1, c2, n2, d2, answer, length))
       {
           cout << "add() returned true\nSum = ";
           for(int i = 0; i < length; i++)
               cout << answer[i];
       }
       else
           cerr << "FALSE" << endl;
       cout << endl << endl;
    
    //if the C string could hold at least the characteristic
    if(subtract(c1, n1, d1, c2, n2, d2, answer, length))
    {
        cout << "subtract() returned true\nDifference = ";
        for(int i = 0; i < length; i++)
            cout << answer[i];
    }
    else
        cerr << "FALSE" << endl;
    cout << endl << endl;
    
    return 0;
}
