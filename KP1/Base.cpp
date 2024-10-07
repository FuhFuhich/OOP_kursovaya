#include "Base.h"
#include <iostream>
using namespace std;
Base::Base(Base *p, std::string name): pBase(p), name(name)
{
	if (pBase!=nullptr) pBase->vecPointers.push_back(this); // Добавляем объект к головному
}
Base::~Base()
{
	for(auto pos: vecPointers) delete pos; // Удаляем подчиненные объекты
}

std::string Base::getName()
{
	return name;
}
bool Base::setName(std::string newName)
{
	if (pBase!=nullptr)
	for(auto pos: pBase->vecPointers) if (pos->name==newName) // Такое имя есть
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
	for(auto pos: vecPointers) // Поиск среди непосредственно подчиненных
		if (pos->name==name) return pos; // Нашли, возвращает указатель на объект
	return nullptr; // Не нашли, nullptr
}
void Base::print() const
{
	if (vecPointers.size()>0) // Есть подчиненные объекты
	{
		cout<<endl<<name; // Имя текущего
		for(auto pos: vecPointers)
		{
			cout<<"  "<<pos->name;// имя подчиненного
			pos->print(); // Вызов для подчиненного
		}
	}
}

