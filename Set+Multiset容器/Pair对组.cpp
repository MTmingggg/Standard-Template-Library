//pair���齫һ��ֵ��ϳ�һ��ֵ�����ֵ���������Ϳ��Բ�һ�����ɷֱ�pair.first()��pair.second()����
//mapҪ�õ��������ȫ�Ƕ���
#include <set>
#include <iostream>
#include <string>
using namespace std;

void test0() {
	//1 ����
	pair<int, int> p1(10, 20);
	cout << p1.first << " " << p1.second << endl;
	
	//2 ��ͬ����
	pair<int, string> p2(10, "156dqw");
	cout << p2.first << " " << p2.second << endl;

	//����
	pair<int, string> p3 = p2;
	cout << p3.first << " " << p3.second << endl;

	//swap
	pair<int, string> p4(1981891, "1wfqf");
	p3.swap(p4);
	cout << p3.first << " " << p3.second << endl;
}

int main(void) {
	test0();

	system("pause");
	return 0;
}