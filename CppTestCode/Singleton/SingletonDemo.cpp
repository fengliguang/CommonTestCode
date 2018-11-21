#include "SingletonDemo.h"

CSingletonDemo::CSingletonDemo(void)
{
	printf("CSingletonDemo\n");
}

CSingletonDemo::~CSingletonDemo(void)
{
	printf("~CSingletonDemo\n");
}

CSingletonDemo & CSingletonDemo::GetInsance()
{
	static CSingletonDemo s_Log;
	return s_Log;
}

int CSingletonDemo::CalcSum(const int & i4A, const int & i4B)
{
	return (i4A + i4B);
}