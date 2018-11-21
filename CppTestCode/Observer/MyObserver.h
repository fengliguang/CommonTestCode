#ifndef _COBSEVER_H_
#define _COBSEVER_H_

#include <iostream>
#include <vector>
#include <map>
using namespace std;


class IObserver
{
public:
	virtual ~IObserver() {}
	virtual void Update(int i4Message) = 0;
};

class ISubject
{
public:
	ISubject();
	virtual ~ISubject();

public:
	virtual void AddObserver(int i4Message, IObserver * pObserver);
	virtual void RemoveObsrver(int i4Message, IObserver * pObserver);
	virtual void NotifyMsg(int i4Message);

private:
	map<int, vector<IObserver*>> m_MapObserver;
};

class MySubject : public ISubject
{
public:
	enum Messages {ADD, REMOVE, UPDATE};
};


//An observer class that wishes to receive a notification
class CMyObserver : public IObserver
{
public:
	CMyObserver(const string &str) : mName(str) {}
	void Update(int message)
	{
		switch (message)
		{
		case MySubject::ADD:
			{
				cout << mName.c_str() << " Received message ADD."<< endl;
				break;
			}
		case MySubject::REMOVE:
			{
				cout << mName.c_str() << " Received message REMOVE."<< endl;
			}
		case MySubject::UPDATE:
			{
				cout << mName.c_str() << " Received message UPDATE."<< endl;
			}
		default:
			break;
		}
		
	}
private:
	string mName;
};

#endif

