#ifndef CL_APP_H_INCLUDED
#define CL_APP_H_INCLUDED

#include "Base.h"
#include "cl_1.h"
class cl_app: public Base
{
	public:
	cl_app(Base *p);// Конструктор
	void build(); // Создание дерева
	int exec(); // Выполнение (печать)

};

#endif // CL_APP_H_INCLUDED
