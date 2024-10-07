#ifndef __BASE__H
#define __BASE__H
#include <string>
#include <vector>
class Base
{
	Base * pBase=nullptr;
	std::string name;
	std::vector<Base *> vecPointers;
	int state=0;  // ���������
public:
	void setState(int state); // ���������� ���������
	Base(Base *p, std::string name="Object");
	std::string getName();
	bool setName(std::string newName);
	Base * getBase();
	Base *getFindName(std::string name);
	~Base();
	Base *search2(std::string name); // ����� ������ ������� �� ����� ������ �������� �� �������� �� �����
	Base *search_from_root(std::string name); // ����� ������ ������� �� ������ �������� �� �����
	void print1() const;
	void print2() const;

};
#endif
