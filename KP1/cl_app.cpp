#include "cl_app.h"
#include <iostream>
using namespace std;
cl_app::cl_app(Base *p): Base(p)
{
}

void cl_app::build()
{
	string sub_name, head_name; // ����� ��������� � ������������ ��������
	Base *pHead=this, *pSub=nullptr; // ��������� �� �������
	cin>>head_name; // ������ ������ - ���� ��������� �������
	setName(head_name); // ������������� ��� ��� ��������� �������
	while(true) // ���� ����� ������
	{
		cin>>head_name>>sub_name; // ���� 2-� ���� ��������
		if (head_name==sub_name) break;// ����� �� �����
		if (pSub!=nullptr && head_name==pSub->getName())
			pHead=pSub; // ������� � ������ ���������
		if (pHead->getFindName(sub_name)==nullptr && head_name==pHead->getName()) // ��� �������� �����
		   pSub=new cl_1(pHead, sub_name); // ������� ����� ������
	}
}
int cl_app::exec()
{
	cout<<getName(); // ������ ������ ������
	print(); // ����������� ������ ���� ��������
	return 0;
}

