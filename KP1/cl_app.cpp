#include "cl_app.h"
#include <iostream>
using namespace std;
cl_app::cl_app(Base *p): Base(p)
{
}

void cl_app::build()
{
	string sub_name, head_name; // Имена головного и подчиненного объектов
	Base *pHead=this, *pSub=nullptr; // Указатели на объекты
	cin>>head_name; // Первая строка - ввод головного объекта
	setName(head_name); // Устанавливаем имя для головного объекта
	while(true) // Цикл ввода данных
	{
		cin>>head_name>>sub_name; // ввод 2-х имен объектов
		if (head_name==sub_name) break;// выход из цикла
		if (pSub!=nullptr && head_name==pSub->getName())
			pHead=pSub; // Переход к новому головному
		if (pHead->getFindName(sub_name)==nullptr && head_name==pHead->getName()) // Нет повтолра имени
		   pSub=new cl_1(pHead, sub_name); // Создаем новый объект
	}
}
int cl_app::exec()
{
	cout<<getName(); // Печать первой строки
	print(); // Рекурсивная печать всей иерархии
	return 0;
}

