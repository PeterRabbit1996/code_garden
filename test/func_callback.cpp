#include<iostream>
 
using namespace std;
 
class CCallback
{
public:
	virtual void onCallbackFunc(int value, int type) = 0;	
};
 
class ClassA
{
public: 
	ClassA(CCallback *pCallbackFunc)
	{
		m_pCallBack = pCallbackFunc;	
	}
 
	void showValue()
	{
		m_pCallBack->onCallbackFunc(15, 0);
		m_pCallBack->onCallbackFunc(17, 1);
	}
private:
	CCallback *m_pCallBack;
 
};

class ClassB : public CCallback
{
public:
	ClassB()
	{
		m_ClassA = new ClassA(this);				
	}
 
	void onCallbackFunc(int value, int type)
	{
		if(type == 0)
		{
			cout<<"Typ_ZERO =  "<< value<<endl;
		}
		else
		{
			cout<<"Typ_Other =  "<< value<<endl;
		}
	}
	void TestShowData()
	{
		m_ClassA->showValue();
	}
public:
	ClassA * m_ClassA;
};

int main(int argc, char* argv[])
{
 
	ClassB *m_classB =new ClassB();
	m_classB->TestShowData();
 
	return 0;
}
