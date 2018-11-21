#include "ClassDemo.h"
#include "MemoryLeakCheck.h"

//ÄÚ´æÐ¹Â¶´òÓ¡
//f:\opensource\github\my\project\commontestcode\trunk\cpptestcode\automemleakcheck\classdemo.cpp(11) : {70} client block at 0x003E18D0, subtype 0, 24 bytes long.
//Data: <Memory Leak     > 4D 65 6D 6F 72 79 20 4C 65 61 6B 00 CD CD CD CD 

CClassDemo::CClassDemo(void)
{
	m_pBuffer = NULL;
	m_pBuffer = new char[24];
}

CClassDemo::~CClassDemo(void)
{
}

void CClassDemo::DoSomething()
{
	strcpy(m_pBuffer, "Memory Leak");	
}