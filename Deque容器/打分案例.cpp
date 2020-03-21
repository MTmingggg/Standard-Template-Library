#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//创建5个选手（姓名，分数），由10个评委对每个选手来打分
//规则：去除最高分、最低分，算出平均分
//按由高到低排序

//选手类
class xuanshou {
public:
	xuanshou() {};
	xuanshou(string Name, int Score) :m_sName(Name), m_iScore(Score) {};
public:
	string m_sName;
	int m_iScore;
};

//创建五个选手，放入vector
void createxuanshou(vector<xuanshou>& v) {
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		xuanshou p;
		p.m_sName += nameSeed[i];
		p.m_iScore = 0;

		v.push_back(p);
	}
}

void printScore(int val) {
	cout << val << " ";
}

//打分
void setScore(vector<xuanshou>& v) {
	for (vector<xuanshou>::iterator it = v.begin(); it != v.end(); it++) {
		//当前学生打分
		deque<int> d;
		for (int i = 0; i < 10; i++) {
			int score = rand() % 41 + 60;
			d.push_back(score);
		}

		//对分数排序
		sort(d.begin(),d.end());
		for_each(d.begin(), d.end(),printScore);
		cout << endl;

		//去除最高分和最低分
		cout << "去除最高分：" << d.front() << endl;
		cout << "去除最低分：" << d.back() << endl;
		d.pop_back();
		d.pop_front();
		for_each(d.begin(), d.end(), printScore);
		cout << endl;

		//求平均分
		int totalScore = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			totalScore += (*dit);
		}
		int avg = totalScore / d.size();

		(*it).m_iScore = avg;
		cout << "平均分："<< avg << endl;
		cout << "---------" << endl;
	}
}

//排序规则
bool mycompare(xuanshou& p1, xuanshou& p2) {
	return p1.m_iScore > p2.m_iScore;
}

//根据分数排序，输出
void printRank(vector<xuanshou>& v) {
	sort(v.begin(), v.end(),mycompare);//v里放的xuanshou对象，用第三个参数
	for (vector<xuanshou>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "姓名：" << (*it).m_sName << "得分：" << (*it).m_iScore << endl;
	}
}

int main(void) {
	//定义一个vector保存选手信息
	vector<xuanshou> v;
	createxuanshou(v);
	setScore(v);
	printRank(v);

	system("pause");
	return 0;
}