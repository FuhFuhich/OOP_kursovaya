#include "cl_app.h"
#include "cl_1.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include <iostream>
using namespace std;
cl_app::cl_app(Base *p): Base(p)
{
}

void cl_app::build()
{
	string sub_name, head_name;
	Base *pHead=this;
	int iClass, iState;
	cin>>head_name;
	setName(head_name);
	while(true) // Ввод дерева
	{
		cin>>head_name;
		if (head_name=="endtree") break; // Выход
		cin>>sub_name>>iClass; // Имя подчиненного объекта и номер класса
		pHead=search_from_root(head_name); // Поиск головного по имени
		if (pHead!=nullptr && pHead->search2(sub_name)==nullptr)
		switch(iClass) // Создаем объект по номеру класса
		{
			case 2: new cl_1(pHead, sub_name); break;
			case 3: new cl_2(pHead, sub_name); break;
			case 4: new cl_3(pHead, sub_name); break;
			case 5: new cl_4(pHead, sub_name); break;
			case 6: new cl_5(pHead, sub_name); break;
		}
	}
	while(cin>>head_name) // Цикл ввода состояний объектов
	{
		cin>>iState;
		search_from_root(head_name)->setState(iState); // Поиск по имени и установка состояния
	//	cout<<head_name<<" "<<iState
	}
}
int cl_app::exec()
{
	cout<<"Object tree\n";
	print1(); // Печать дерева
	cout<<"The tree of objects and their readiness\n";
	print2(); // Печать готовностей элементов
	return 0;
}

