#include "main.h"
#include <iostream>

using namespace std;

int Solution::leftMostColumnWithOne(BinaryMatrix &binaryMatrix)
{
	vector<int> dimensions = binaryMatrix.dimensions();
	int res = -1;
	int m = 0;
	int n = dimensions[1] - 1;
	while (n >= 0 && m < dimensions[0])
	{
		cout << binaryMatrix.get(m, n);
		if (binaryMatrix.get(m, n) == 1)
		{
			//Move left
			res = n;
			n--;
		}
		else
		{
			//Move down
			m++;
		}
	}
	return res;
}

int main()
{
	return 0;
}