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
	for(auto pos: vecPointers) // Ищем только среди подчиненных
		if (pos->name==name) return pos;
	return nullptr;
}

Base *Base::search2(std::string name) // метод поиска объекта на ветке дереве иерархии от текущего по имени
{
    Base *pFind=nullptr; // Искомый элемент
	queue<Base *> q; // Очередь
	q.push(this); // Текущий элемент - первый в очереди
	while(!q.empty()) // Перебор дерева в ширину, пока элементы в очереди есть
	{
		if (q.front()->name==name)
			if (pFind==nullptr) pFind=q.front(); // Сохраняем найденный указатель
            else return nullptr; // Уже есть такой элемент возвращаем nullptr
		for(auto p: q.front()->vecPointers) // Подчиненные элементы добавляем в очередь
			q.push(p);
		q.pop(); // Удаляем первый элемент из очереди
	}
	return pFind;
}

Base *Base::search_from_root(std::string name) // метод поиска объекта на дереве иерархии по имени
{
	Base *p=this;
	while(p->pBase!=nullptr) p=p->pBase; // Перемещаемся к головному элементу
	return p->search2(name);
}

void Base::print1() const   // Печать дерева
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

void Base::print2() const // // Печать дерева c указанием готовности
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
	if (state!=0) // Устанавливаем не 0, если все элементы выше по дереву установлены не 0
	{
		Base *p=pBase;
		bool flag=true; // Флаг
		while(p!=nullptr) // Проверяем элементы выше по дереву
		{
			if (p->state==0) // нашли элемент выше с состоянием 0
			{
				flag=false;
				break;
			}
			p=p->pBase;
		}
		if (flag) this->state=state; // Устанавливаем не 0, если все элементы выше по дереву установлены не 0
	}
	else // Устанавливаем 0
	{
		for(auto p: vecPointers) // Устанавливаем 0 для всех подчиненных объекетов
			p->setState(0);
		this->state=0;
	}
}
