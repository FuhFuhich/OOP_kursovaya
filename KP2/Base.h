#ifndef __BASE__H
#define __BASE__H
#include <string>
#include <vector>
class Base
{
	Base * pBase=nullptr;
	std::string name;
	std::vector<Base *> vecPointers;
	int state=0;  // Состояние
public:
	void setState(int state); // Установить состояние
	Base(Base *p, std::string name="Object");
	std::string getName();
	bool setName(std::string newName);
	Base * getBase();
	Base *getFindName(std::string name);
	~Base();
	Base *search2(std::string name); // метод поиска объекта на ветке дереве иерархии от текущего по имени
	Base *search_from_root(std::string name); // метод поиска объекта на дереве иерархии по имени
	void print1() const;
	void print2() const;

};
#endif
