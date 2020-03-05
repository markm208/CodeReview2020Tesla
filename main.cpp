#include <iostream>
#include "multiplyDivide.h"

using namespace std;

int main()
{
	char multiplyResult[10];
	char divideResult[10];

	if (multiply(2, 35, 100, 15, 35, 100, multiplyResult, 10))
	{
		for (int i = 0; i < 10; i++)
		{
			cout << multiplyResult[i] << endl;
		}
	}

	if (divide(2, 35, 100, 15, 35, 100, divideResult, 10))
	{
		for (int i = 0; i < 10; i++)
		{
			cout << divideResult[i];
		}
	}
	return 0;
}