#include "ClassDemo.h"
#include "MemoryLeakCheck.h"

//ÄÚ´æÐ¹Â¶´òÓ¡Detected memory leaks!
//f:\opensource\github\my\project\commontestcode\trunk\cpptestcode\automemleakcheck\automemleakcheck.cpp(10) : {69} client block at 0x003E1890, subtype 0, 4 bytes long.
//Data: <  ~ > D0 18 7E 00 

int main(int argc, char **argv)
{
	CClassDemo * pClassDemo = new CClassDemo();
	pClassDemo->DoSomething();
	getchar();
	return 0;
}