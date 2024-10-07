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
		pHead=getObjectCoor(head_name);
		if (pHead!=nullptr && pHead->getFindName(sub_name)==nullptr)
		switch(iClass) // Создаем объект по номеру класса
		{
			case 2: new cl_1(pHead, sub_name); break;
			case 3: new cl_2(pHead, sub_name); break;
			case 4: new cl_3(pHead, sub_name); break;
			case 5: new cl_4(pHead, sub_name); break;
			case 6: new cl_5(pHead, sub_name); break;
		}
		else
			if (pHead==nullptr)
			{
				cout<<"Object tree\n";
				print1();
				cout<<"The head object "<<head_name<<" is not found"<<endl;
				exit(1);
			}
			else
			{
				cout<<head_name<<"    Dubbing the names of subordinate objects"<<endl;
			}
	}

}
int cl_app::exec()
{
	cout<<"Object tree\n";
	print1(); // Печать дерева
	string comm, coord;
	Base *pCur=this, *p;
	while(true)
	{
		cin>>comm;
		if (comm=="END") break;
		cin>>coord;
		p=pCur->getObjectCoor(coord);
		if (comm=="SET")
		{
			if (p!=nullptr)
			{
				pCur=p;
				cout<<"Object is set: "<<pCur->getName()<<endl;
			}
			else cout<<" The object was not found at the specified coordinate: "<<coord<<endl;
			continue;
		}
		if (comm=="FIND")
		{
			cout<<coord<<"     Object ";
			if (p!=nullptr) cout<<"name: "<<p->getName()<<endl;
			else cout<<"is not found"<<endl;
			continue;
		}
		if (comm=="MOVE")
		{
			if (pCur->newBase(p)) cout<<"New head object: "<<p->getName()<<endl;
			else
			{
				if (pCur->getBase()==nullptr) cout<<coord<<"     Redefining the head object failed"<<endl;
				else
					if (p==nullptr)
						cout<<coord<<"     Head object is not found"<<endl;
				else
					if (p->getFindName(pCur->getName()))
						cout<<coord<<"     Dubbing the names of subordinate objects"<<endl;
				else {
					while(p!=nullptr)
					{
						if (p==pCur) {
							cout<<coord<<"     Redefining the head object failed"<<endl; break;
							break;
						}
						p=p->getBase();
					}
				}
			}
			continue;
		}
		if (comm=="DELETE")
		{
			if (p!=nullptr)
			{
				vector<string> vecName;
				auto pos=p;
				while(pos->getBase()!=nullptr)
				{
					vecName.push_back(pos->getName());
					pos=pos->getBase();
				}
				pCur->delSub(coord);
				cout<<"The object ";
				for(auto it=vecName.rbegin(); it!=vecName.rend(); ++it)
					cout<<"/"<<*it;
				cout<<" has been deleted"<<endl;
			}
			continue;
		}
	}
	cout<<"Current object hierarchy tree"<<endl;
	print1();
	return 0;
}

