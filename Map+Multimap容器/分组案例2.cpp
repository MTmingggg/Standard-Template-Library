#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define sale 1
#define development 2
#define financial 3

//Multimap ����:
//��˾�����۲� sale�������з��� development������ Financial
//��Ա��Ϣ�У����������䣬�绰���������
//ͨ�� multimap���� ��Ϣ�Ĳ��롢����
//�ֲ�����ʾԱ����Ϣ 

//����˼·��multimap<string, Person>��keyΪ����string��valueΪperson���󣬶����а�����Ϣ�������ظ�

class Person {
public:
	string		name;
	int			age;
	string		tel;
	double	saly;
};

//����Ա��
void createWorker(vector<Person>& vperson) {
	string setName = "ABCDE";
	for (int i = 0; i < 5; i++) {
		Person p;
		p.name = "Ա��";
		p.name += setName[i];

		p.age = rand() % 10 + 20;
		p.saly = rand() % 1000 + 16000;
		p.tel = "010-67894532";
		//����Ա����Ϣ
		vperson.push_back(p);
	}
}

//����
void byGroup(vector<Person>& vperson, multimap<int, Person>& mgroup) {
	//Ա���������
	srand(time(NULL));
	for (vector<Person>::iterator it = vperson.begin(); it != vperson.end(); it++) {
		int ID = rand() % 3 + 1;
		switch (ID)
		{
		case 1:
			mgroup.insert(make_pair(1, (*it)));
			break;
		case 2:
			mgroup.insert(make_pair(2, (*it)));
			break;
		case 3:
			mgroup.insert(make_pair(3, (*it)));
			break;
		}
	}
	//��ӡ����Ա��
	cout << "������ְԱ����Ϣ��" << endl;
	for (multimap<int, Person>::iterator it = mgroup.begin(); it != mgroup.end(); it++){
		cout << "������" << it->second.name << " ���䣺" << it->second.age << " ���ʣ�" << it->second.saly << endl;
	}
}

//��ӡ
void showPerson(multimap<int, Person>& mgroup, int ID) {
	//��ӡsale��Ҫ�жϲ��ű�ţ��ҵ���ʼ���������֪����һ����ͬ�ĳ��֣���Ҫ֪��key��ͬ��Ԫ�صĸ���mgroup.count(ID)
	multimap<int, Person>::iterator it1 = mgroup.find(ID);//��һ���ҵ��ĵ�����
	
	//����������
	int num = mgroup.count(ID);

	int c = 0;//������ѭ����ͳ��
	//����
	for (multimap<int, Person>::iterator it = it1; it != mgroup.end() && c < num; it++,c++) {
		cout << "������" << it->second.name << "���䣺" << it->second.age << "���ʣ�" << it->second.saly << endl;
	}
}
	
void printInfo(multimap<int, Person>& mgroup) {
	cout << "��������" << endl;
	cout << "sale:" << endl;
	showPerson(mgroup, 1);

	cout << "development:" << endl;
	showPerson(mgroup, 2);

	cout << "financial:" << endl;
	showPerson(mgroup, 3);
}

int main(void) {
	//�����Ա����Ϣ
	vector<Person> vp;
	//multimap���������Ϣ
	multimap<int, Person> mg;

	//����Ա��
	createWorker(vp);
	//����
	byGroup(vp,mg);
	//��ӡ
	printInfo(mg);

	system("pause");
	return 0;
}