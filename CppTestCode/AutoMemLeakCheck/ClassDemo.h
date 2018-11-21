#pragma once
#include <string.h>
#include <stdio.h>

class CClassDemo
{
public:
	 CClassDemo(void);
	~CClassDemo(void);
public:
	void DoSomething();
private:
	char * m_pBuffer;
};
