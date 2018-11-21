#include "SingletonDemo.h"

int main(int argc, char **argv)
{
	CSingletonDemo &myLog = CSingletonDemo::GetInsance();
	printf("10 + 45 = %d\n", myLog.CalcSum(10, 45));
	getchar();
	return 0;
}