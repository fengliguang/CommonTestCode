#ifndef _SINGLEDEMO_H_
#define _SINGLEDEMO_H_

#include <stdio.h>

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
	TypeName(const TypeName &);\
	const TypeName & operator = (const TypeName &)\

class CSingletonDemo
{
public:
	static CSingletonDemo & GetInsance();

public:
	int CalcSum(const int & i4A, const int & i4B);

private:
	CSingletonDemo(void);
	~CSingletonDemo(void);

	DISALLOW_COPY_AND_ASSIGN(CSingletonDemo);
};




#endif