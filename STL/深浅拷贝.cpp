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

	//��������
	Person(const Person& p) {
		pName = new char[strlen(p.pName) + 1];
		strcpy(pName, p.pName);
		m_iAge = p.m_iAge;
	}
	//���� = 
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
	char* pName;//ָ�룬���׳���ǳ��������
	int m_iAge;
};

void test() {
	vector<Person> vp;
	Person p("qwer", 12);
	vp.push_back(p);//������һ�ݷŽ�ȥ������������ָ����ڴ棬��Ҫ�����������Ե����ˡ�
	//�������Լ���ָ���Լ���->���ӿ�������->����=
}

int main(void) {
	test();

	system("pause");
	return 0;
}