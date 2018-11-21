#include "MyObserver.h"

int main(int argc, char **argv)
{
	CMyObserver observer1("BASE_001");
	CMyObserver observer2("BASE_002");
	CMyObserver observer3("BASE_003");

	MySubject subject;
	subject.AddObserver(MySubject::ADD,    &observer1);
	subject.AddObserver(MySubject::ADD,    &observer2);
	subject.AddObserver(MySubject::ADD,    &observer3);
	subject.AddObserver(MySubject::REMOVE, &observer1);
	subject.AddObserver(MySubject::UPDATE, &observer2);
	subject.AddObserver(MySubject::UPDATE, &observer3);

	subject.NotifyMsg(MySubject::ADD);
	subject.NotifyMsg(MySubject::REMOVE);
	subject.NotifyMsg(MySubject::UPDATE);

	cout << endl;

	subject.RemoveObsrver(MySubject::ADD, &observer1);
	subject.RemoveObsrver(MySubject::REMOVE, &observer1);
	subject.RemoveObsrver(MySubject::UPDATE, &observer1);

	subject.NotifyMsg(MySubject::ADD);
	subject.NotifyMsg(MySubject::REMOVE);
	subject.NotifyMsg(MySubject::UPDATE);

	getchar();
	return 0;
}