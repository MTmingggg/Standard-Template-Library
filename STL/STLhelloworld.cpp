#include<iostream>
#include<vector>//动态数组  可变数组
#include<algorithm>
using namespace std;

//for_each第三个参数——回调函数
void printVectorCallback(int v) {//传入的参数与vector<int>放入的对象类型一致
	cout << v << " ";
}

//STL基本语法  容器 算法 迭代器
void test0() {
	//定义一个容器，并且制定容器元素存放类型为int
	vector<int> v;
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	//通过STL提供的for_each()算法进行遍历
	//容器提供的迭代器
	vector<int>::iterator pBegin = v.begin();//返回的迭代器类型，pBegin指向第一个
	vector<int>::iterator pEnd = v.end();//pEnd指向最后一个的下一个

	//容器中可能存放基础数据类型，也可能存放自定义数据类型，所以遍历时需要第三个参数回调去打印
	for_each(pBegin, pEnd, printVectorCallback);//算法
}



//容器也可以存放自定义数据类型
class person {
public:
	person(int age, int id) :m_iAge(age), m_iId(id) {}
public:
	int m_iAge;
	int m_iId;
};

void test1() {
	//创建容器，并指定person类型元素
	vector<person> vp;
	person p1(10, 20), p2(30, 40), p3(50, 60);

	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);

	//自行用迭代器进行遍历
	for (vector<person>::iterator it = vp.begin();  it != vp.end(); it++) {
		//这里的*it就是个person对象
		cout << (*it).m_iAge << " ";
	}
}

//int main(void) {
//	test0();
//	cout << endl;
//	test1();
//	system("pause");
//	return 0;
//}