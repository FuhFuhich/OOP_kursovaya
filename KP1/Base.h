#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED
#include <string>
#include <vector>
class Base
{
	Base * pBase=nullptr; // ��������� �� �������� ������
	std::string name; // ���
	std::vector<Base *> vecPointers; // ������ (������) �� ����������� �������
public:
	Base(Base *p, std::string name="Object"); // ������������������� ����������� � �����������: ��������� �� �������� ������
	std::string getName(); // �������� ���
	bool setName(std::string newName); // ���������� ���
	Base * getBase(); // �������� ��������� �� �������� ������
	Base *getFindName(std::string name); // ����� ������� �� �����
	void print() const; // ������
	~Base(); // ����������

};


#endif // BASE_H_INCLUDED
