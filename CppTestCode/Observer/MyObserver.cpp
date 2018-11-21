#include "MyObserver.h"

ISubject::ISubject(void)
{
	cout << "ISubject" << endl;
}

ISubject::~ISubject(void)
{
	cout << "~ISubject" << endl;
}

void ISubject::AddObserver(int i4Message, IObserver * pObserver)
{
	if (NULL != pObserver)
	{
		map<int, vector<IObserver*>>::iterator it = m_MapObserver.find(i4Message);
		if (it == m_MapObserver.end())
		{
			m_MapObserver[i4Message] = vector<IObserver*>();
		}
		m_MapObserver[i4Message].push_back(pObserver);
	}
}

void ISubject::RemoveObsrver(int i4Message, IObserver * pObserver)
{
	map<int, vector<IObserver*>>::iterator it = m_MapObserver.find(i4Message);
	if (it != m_MapObserver.end())
	{
		vector<IObserver*> &list = m_MapObserver[i4Message];
		vector<IObserver*>::iterator itv;
		for (itv = list.begin(); itv != list.end();)
		{
			if ((*itv) == pObserver)
			{
				itv = list.erase(itv);
			}
			else
			{
				++itv;
			}
		}
	}
}

void ISubject::NotifyMsg(int i4Message)
{
	map<int, vector<IObserver*>>::iterator it = m_MapObserver.find(i4Message);
	if (it != m_MapObserver.end())
	{
		vector<IObserver*> &list = m_MapObserver[i4Message];
		vector<IObserver*>::iterator itv;
		for (itv = list.begin(); itv != list.end();++itv)
		{
			(*itv)->Update(i4Message);
		}
	}
}