#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//����һ���º���
class Myprint {
public:
	Myprint() {
		m_iNum = 0;
	}
	//����()����������Ϊ����������
	void operator()(int val) {
		m_iNum ++;
		cout << "val = " << val << endl;
	}
	void ppp() {
		cout << "������Ա��������ʹ�ã�" << endl;
	}
public:
	int m_iNum;
};

void test0() {
	Myprint print;
	print(15);
	//���������������ͨ����һ��������
	//���������������ͨ����һ�����ղ���
	//�������󳬳�����������Ա������״̬
}

void test1() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	Myprint print;
	Myprint p1 = for_each(v.begin(), v.end(), print);//for_each��������ע����-���º���
	//print��p1˭��������ȷ������
	cout << "p1.m_iNum = " << p1.m_iNum << "    print.m_iNum = " << print.m_iNum << endl;
	//������ȷ��������p1.m_iNum����Ϊfor_each���������Կ�����ʽ���룬��ʱ�������Ѿ�����һ������p1����

	//�º����п�����ʹ��������Ա����
	p1.ppp();
}

int main(void) {
	test0();
	test1();

	system("pause");
	return 0;
}