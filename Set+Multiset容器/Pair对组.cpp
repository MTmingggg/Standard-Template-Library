//pair对组将一对值组合成一个值，这对值的数据类型可以不一样，可分别被pair.first()和pair.second()访问
//map要用到，插入的全是对组
#include <set>
#include <iostream>
#include <string>
using namespace std;

void test0() {
	//1 构造
	pair<int, int> p1(10, 20);
	cout << p1.first << " " << p1.second << endl;
	
	//2 不同类型
	pair<int, string> p2(10, "156dqw");
	cout << p2.first << " " << p2.second << endl;

	//拷贝
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