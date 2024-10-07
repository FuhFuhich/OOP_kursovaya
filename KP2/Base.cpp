#include "Base.h"
#include <iostream>
#include <queue>
using namespace std;
Base::Base(Base *p, std::string name): pBase(p), name(name)
{
	if (pBase!=nullptr) pBase->vecPointers.push_back(this);
}
Base::~Base()
{
	for(auto pos: vecPointers) delete pos;
}

std::string Base::getName()
{
	return name;
}
bool Base::setName(std::string newName)
{
	if (pBase!=nullptr)
	for(auto pos: pBase->vecPointers) if (pos->name==newName)
		return false;
	name=newName;
	return true;
}

Base * Base::getBase()
{
	return pBase;
}

Base * Base::getFindName(std::string name)
{
	for(auto pos: vecPointers) // ���� ������ ����� �����������
		if (pos->name==name) return pos;
	return nullptr;
}

Base *Base::search2(std::string name) // ����� ������ ������� �� ����� ������ �������� �� �������� �� �����
{
    Base *pFind=nullptr; // ������� �������
	queue<Base *> q; // �������
	q.push(this); // ������� ������� - ������ � �������
	while(!q.empty()) // ������� ������ � ������, ���� �������� � ������� ����
	{
		if (q.front()->name==name)
			if (pFind==nullptr) pFind=q.front(); // ��������� ��������� ���������
            else return nullptr; // ��� ���� ����� ������� ���������� nullptr
		for(auto p: q.front()->vecPointers) // ����������� �������� ��������� � �������
			q.push(p);
		q.pop(); // ������� ������ ������� �� �������
	}
	return pFind;
}

Base *Base::search_from_root(std::string name) // ����� ������ ������� �� ������ �������� �� �����
{
	Base *p=this;
	while(p->pBase!=nullptr) p=p->pBase; // ������������ � ��������� ��������
	return p->search2(name);
}

void Base::print1() const   // ������ ������
{
	Base *p=pBase;
	while(p!=nullptr)
	{
		cout<<"    "; p=p->pBase;
	}
	cout<<name<<endl;
	for(auto p: vecPointers)
		p->print1();
}

void Base::print2() const // // ������ ������ c ��������� ����������
{
	Base *p=pBase;
	while(p!=nullptr)
	{
		cout<<"    "; p=p->pBase;
	}
	cout<<name;
	if (state!=0) cout<<" is ready";
	else cout<<" is not ready";
	cout<<endl;
	for(auto p: vecPointers)
		p->print2();
}

void Base::setState(int state)
{
	if (state!=0) // ������������� �� 0, ���� ��� �������� ���� �� ������ ����������� �� 0
	{
		Base *p=pBase;
		bool flag=true; // ����
		while(p!=nullptr) // ��������� �������� ���� �� ������
		{
			if (p->state==0) // ����� ������� ���� � ���������� 0
			{
				flag=false;
				break;
			}
			p=p->pBase;
		}
		if (flag) this->state=state; // ������������� �� 0, ���� ��� �������� ���� �� ������ ����������� �� 0
	}
	else // ������������� 0
	{
		for(auto p: vecPointers) // ������������� 0 ��� ���� ����������� ���������
			p->setState(0);
		this->state=0;
	}
}
