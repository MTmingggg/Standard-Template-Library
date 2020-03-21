#include<iostream>
#include<vector>
using namespace std;

class Person {
public:
	Person(char* name, int age) {
		pName = new char[strlen(name) + 1];
		strcpy(pName, name);
		m_iAge = age;
	}
	~Person() {
		if (pName != NULL) {
			delete[] pName;
		}
	}

	//拷贝构造
	Person(const Person& p) {
		pName = new char[strlen(p.pName) + 1];
		strcpy(pName, p.pName);
		m_iAge = p.m_iAge;
	}
	//重载 = 
	Person& operator=(const Person& p) {
		if (pName != NULL) {
			delete[] pName;
		}
		pName = new char[strlen(p.pName) + 1];
		strcpy(pName, p.pName);
		m_iAge = p.m_iAge;

		return* this;
	}
public:
	char* pName;//指针，容易出现浅拷贝问题
	int m_iAge;
};

void test() {
	vector<Person> vp;
	Person p("qwer", 12);
	vp.push_back(p);//拷贝了一份放进去，所以两个都指向堆内存，都要调析构，所以荡掉了。
	//必须让自己的指向自己的->增加拷贝构造->重载=
}

int main(void) {
	test();

	system("pause");
	return 0;
}