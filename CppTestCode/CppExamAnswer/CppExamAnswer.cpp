#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define		ZERO    1E-10

/*
写一函数函数将一组浮点型数组，剔除重复的数并按从小到大输出。 
例如输入随机数组13.0000，12.0000，14.0000，11.0000，13.0000，11.0000，12.0000，
执行函数后应该输出11.0000，12.0000，13.0000，14.0000。
*/

void SortAndRemoveRepeat(double f8TempArry[], const int i4Num, vector<double> & vecOutTemp)
{
	vector<double> vecTempIn;
	bool   bInfirst   = true;
	double f8CurTemp  = 0.0;
	double f8LastTemp = 0.0;
	for(int i = 0; i < i4Num; i++)
	{
		vecTempIn.push_back(f8TempArry[i]);
	}
	sort(vecTempIn.begin(), vecTempIn.end());
	for (vector<double>::iterator it = vecTempIn.begin(); it != vecTempIn.end();)
	{
		f8CurTemp = *it;
		if (true == bInfirst)
		{
			vecOutTemp.push_back(f8CurTemp);
			++it;
			bInfirst = false;
		}
		else
		{
			if (fabs(f8CurTemp - f8LastTemp) < ZERO )
			{
				it = vecTempIn.erase(it);
			}
			else
			{
				vecOutTemp.push_back(f8CurTemp);
				++it;
			}
		}
		f8LastTemp = f8CurTemp;
	}
}

int main(int argc, char **argv)
{
	double f8TempArry[6] = {13.0000, 14.0000, 11.0000, 13.0000, 11.0000, 12.0000};
	vector<double> vecOutTemp;
	SortAndRemoveRepeat(f8TempArry, sizeof(f8TempArry)/sizeof(double), vecOutTemp);
	for (vector<double>::iterator it = vecOutTemp.begin(); it != vecOutTemp.end(); it++ )
	{
		printf("%.4f\n", *it);
	}
	system("pause");
	return 0;
}