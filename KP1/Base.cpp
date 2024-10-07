#include "Base.h"
#include <iostream>
using namespace std;
Base::Base(Base *p, std::string name): pBase(p), name(name)
{
	if (pBase!=nullptr) pBase->vecPointers.push_back(this); // ��������� ������ � ���������
}
Base::~Base()
{
	for(auto pos: vecPointers) delete pos; // ������� ����������� �������
}

std::string Base::getName()
{
	return name;
}
bool Base::setName(std::string newName)
{
	if (pBase!=nullptr)
	for(auto pos: pBase->vecPointers) if (pos->name==newName) // ����� ��� ����
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
	for(auto pos: vecPointers) // ����� ����� ��������������� �����������
		if (pos->name==name) return pos; // �����, ���������� ��������� �� ������
	return nullptr; // �� �����, nullptr
}
void Base::print() const
{
	if (vecPointers.size()>0) // ���� ����������� �������
	{
		cout<<endl<<name; // ��� ��������
		for(auto pos: vecPointers)
		{
			cout<<"  "<<pos->name;// ��� ������������
			pos->print(); // ����� ��� ������������
		}
	}
}

