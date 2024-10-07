#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED
#include <string>
#include <vector>
class Base
{
	Base * pBase=nullptr; // Указатель на головной объект
	std::string name; // Имя
	std::vector<Base *> vecPointers; // Массив (вектор) на подчиненные объекты
public:
	Base(Base *p, std::string name="Object"); // параметризированный конструктор с параметрами: указатель на головной объект
	std::string getName(); // получить имя
	bool setName(std::string newName); // установить имя
	Base * getBase(); // получить указатель на головной объект
	Base *getFindName(std::string name); // поиск объекта по имени
	void print() const; // Печать
	~Base(); // деструктор

};


#endif // BASE_H_INCLUDED
