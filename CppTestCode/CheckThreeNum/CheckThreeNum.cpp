#include <iostream>
using namespace std;

bool bIsEqual(const int & i4A, const int & i4B, const int & i4C, const int & i4a, const int & i4b, const int & i4c)
{
	bool bEqual = false;
	if (i4A == i4a) //1-2-3    1-3-2
	{
		if ( (i4B == i4b && i4C == i4c) || (i4B == i4c && i4C == i4b))
		{
			return true;
		}
	}
	else if (i4A == i4b) //2-3-1  2-1-3
	{
		if ( (i4B == i4c && i4C == i4a) || (i4B == i4a && i4C == i4c))
		{
			return true;
		}
	}
	else if (i4A == i4c) //3-1-2 3-2-1
	{
		if ( (i4B == i4a && i4C == i4b) || (i4B == i4b && i4C == i4a))
		{
			return true;
		}
	}
	return bEqual;
}

int main()
{
	int i4A = 2;
	int i4B = 4;
	int i4C = 14;

	int i4a = 14;
	int i4b = 2;
	int i4c = 4;

	if (true == bIsEqual(i4A, i4B, i4C, i4a, i4b, i4c))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}

	system("pause");
	return 0;
}