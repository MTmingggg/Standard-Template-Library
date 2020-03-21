#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//这是一个仿函数
class Myprint {
public:
	Myprint() {
		m_iNum = 0;
	}
	//重载()后类对象可作为函数对象传入
	void operator()(int val) {
		m_iNum ++;
		cout << "val = " << val << endl;
	}
	void ppp() {
		cout << "正常成员函数可以使用！" << endl;
	}
public:
	int m_iNum;
};

void test0() {
	Myprint print;
	print(15);
	//函数对象可以像普通函数一样被调用
	//函数对象可以像普通函数一样接收参数
	//函数对象超出函数概念，可以保存调用状态
}

void test1() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	Myprint print;
	Myprint p1 = for_each(v.begin(), v.end(), print);//for_each遍历，关注三参-》仿函数
	//print和p1谁保存了正确次数？
	cout << "p1.m_iNum = " << p1.m_iNum << "    print.m_iNum = " << print.m_iNum << endl;
	//返回正确次数的是p1.m_iNum，因为for_each的三参是以拷贝形式传入，这时操作的已经是另一个对象（p1）了

	//仿函数中可正常使用其他成员函数
	p1.ppp();
}

int main(void) {
	test0();
	test1();

	system("pause");
	return 0;
}