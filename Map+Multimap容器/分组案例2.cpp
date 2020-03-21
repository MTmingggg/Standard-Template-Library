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

//Multimap 案例:
//公司有销售部 sale、技术研发部 development、财务部 Financial
//人员信息有：姓名，年龄，电话、工资组成
//通过 multimap进行 信息的插入、保存
//分部门显示员工信息 

//核心思路：multimap<string, Person>中key为部门string，value为person对象，对象中包含信息。允许重复

class Person {
public:
	string		name;
	int			age;
	string		tel;
	double	saly;
};

//创建员工
void createWorker(vector<Person>& vperson) {
	string setName = "ABCDE";
	for (int i = 0; i < 5; i++) {
		Person p;
		p.name = "员工";
		p.name += setName[i];

		p.age = rand() % 10 + 20;
		p.saly = rand() % 1000 + 16000;
		p.tel = "010-67894532";
		//保存员工信息
		vperson.push_back(p);
	}
}

//分组
void byGroup(vector<Person>& vperson, multimap<int, Person>& mgroup) {
	//员工随机分配
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
	//打印所有员工
	cout << "所有入职员工信息：" << endl;
	for (multimap<int, Person>::iterator it = mgroup.begin(); it != mgroup.end(); it++){
		cout << "姓名：" << it->second.name << " 年龄：" << it->second.age << " 工资：" << it->second.saly << endl;
	}
}

//打印
void showPerson(multimap<int, Person>& mgroup, int ID) {
	//打印sale，要判断部门编号，找到后开始往后遍历，知道下一个不同的出现，需要知道key相同的元素的个数mgroup.count(ID)
	multimap<int, Person>::iterator it1 = mgroup.find(ID);//第一次找到的迭代器
	
	//部门总人数
	int num = mgroup.count(ID);

	int c = 0;//用来在循环里统计
	//遍历
	for (multimap<int, Person>::iterator it = it1; it != mgroup.end() && c < num; it++,c++) {
		cout << "姓名：" << it->second.name << "年龄：" << it->second.age << "工资：" << it->second.saly << endl;
	}
}
	
void printInfo(multimap<int, Person>& mgroup) {
	cout << "分配结果：" << endl;
	cout << "sale:" << endl;
	showPerson(mgroup, 1);

	cout << "development:" << endl;
	showPerson(mgroup, 2);

	cout << "financial:" << endl;
	showPerson(mgroup, 3);
}

int main(void) {
	//存放新员工信息
	vector<Person> vp;
	//multimap保存分组信息
	multimap<int, Person> mg;

	//创建员工
	createWorker(vp);
	//分组
	byGroup(vp,mg);
	//打印
	printInfo(mg);

	system("pause");
	return 0;
}