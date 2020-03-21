#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//����5��ѡ�֣�����������������10����ί��ÿ��ѡ�������
//����ȥ����߷֡���ͷ֣����ƽ����
//���ɸߵ�������

//ѡ����
class xuanshou {
public:
	xuanshou() {};
	xuanshou(string Name, int Score) :m_sName(Name), m_iScore(Score) {};
public:
	string m_sName;
	int m_iScore;
};

//�������ѡ�֣�����vector
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

//���
void setScore(vector<xuanshou>& v) {
	for (vector<xuanshou>::iterator it = v.begin(); it != v.end(); it++) {
		//��ǰѧ�����
		deque<int> d;
		for (int i = 0; i < 10; i++) {
			int score = rand() % 41 + 60;
			d.push_back(score);
		}

		//�Է�������
		sort(d.begin(),d.end());
		for_each(d.begin(), d.end(),printScore);
		cout << endl;

		//ȥ����߷ֺ���ͷ�
		cout << "ȥ����߷֣�" << d.front() << endl;
		cout << "ȥ����ͷ֣�" << d.back() << endl;
		d.pop_back();
		d.pop_front();
		for_each(d.begin(), d.end(), printScore);
		cout << endl;

		//��ƽ����
		int totalScore = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			totalScore += (*dit);
		}
		int avg = totalScore / d.size();

		(*it).m_iScore = avg;
		cout << "ƽ���֣�"<< avg << endl;
		cout << "---------" << endl;
	}
}

//�������
bool mycompare(xuanshou& p1, xuanshou& p2) {
	return p1.m_iScore > p2.m_iScore;
}

//���ݷ����������
void printRank(vector<xuanshou>& v) {
	sort(v.begin(), v.end(),mycompare);//v��ŵ�xuanshou�����õ���������
	for (vector<xuanshou>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "������" << (*it).m_sName << "�÷֣�" << (*it).m_iScore << endl;
	}
}

int main(void) {
	//����һ��vector����ѡ����Ϣ
	vector<xuanshou> v;
	createxuanshou(v);
	setScore(v);
	printRank(v);

	system("pause");
	return 0;
}