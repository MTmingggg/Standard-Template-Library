#include <string>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <functional>//内建函数
#include <iostream>
using namespace std;

//仿函数适配器 bind1stbind2nd
//仿函数适配器 not1 not2
//仿函数适配器 ptr_fun.
//成员函数适配器 mem_fun mem_fun_ref

struct  Myprint01: public binary_function<int,int,void>//必须按照这个要求继承一个父类binary_function<int,int,void>，一二参是重载传入的两个类型
{
	void operator()(int v,int val) const {//二：想到在这里多传入一个参数int val 下一行v+val。但是不可行，因为for_each只能进一个参数，这就要绑定适配器转成一个参数
		//四：必须按照要求加上const
		cout << "v= " << v << " val= " << val;
		cout << " v+val= " << v + val <<" "<< endl;
	}
};

//绑定适配器
void test0() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	//一：出现需求：我希望传出来的值每个都加一个val
	for_each(v.begin(), v.end(),bind2nd(Myprint01(),100));
	//bind2nd将一个二元函数对象转化成一元函数对象
	cout << endl;
	//bind1st和bind2nd有什么区别？
	for_each(v.begin(), v.end(), bind1st(Myprint01(), 100));
    //bind1st，将addnum绑定为函数对象的一参
	//bind2nd，将addnum绑定为函数对象的二参
}


//从小到大
struct  Mycompare : public binary_function<int, int, bool>
{
	bool operator()(int v1, int v2) const {//二元谓词
		return v1 < v2;
	}
};

struct  Myprint02
{
	void operator()(int v) {
		cout << v << " ";
	}
};

//找比5小的第一个数。要求不允许改变重载内容
struct  Mygreater5 : public unary_function<int, bool>
{
	bool operator()(int v1) const {//一元谓词
		return v1 > 5;//比5大
	}
};

//取反适配器 not1 not2
void test1() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(rand() % 100);
	}
	for_each(v.begin(), v.end(), Myprint02());
	cout << endl;
	sort(v.begin(), v.end(), not2(Mycompare()));//如果我希望不更改Myprint02而改变排序顺序，就要在这里加not2（二元谓词），同时为三参加public binary_function<int, int, bool>
	for_each(v.begin(), v.end(), Myprint02());
	cout << endl;

	//not1和not2有什么区别？
	//对二元谓词取反，用not2  binary_function
	//对一元谓词取反，用not1  unary_function
	vector<int>::iterator it = find_if(v.begin(), v.end(), not1(Mygreater5()));
	if (it == v.end()) {
		cout << "未找到比5小的数" << endl;
	}
	else {
		cout << *it << endl;
	}
}

//普通函数
void Myprint03(int v1, int v2) {
	cout << v1 << " "<<  v2 << " " << endl;
}

//仿函数适配器 ptr_fun
void test2() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(rand() % 100);
	}
	//问题：绑定时都是函数对象,***有时候需要给函数绑个参数
	//需要把普通函数 转成 函数对象 ptr_fun
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(Myprint03), 10));//先用ptr_fun()转化成函数对象，再用bind2nd()多绑一个参数
}


//成员函数适配器 mem_fun mem_fun_ref
//如果容器中存放的是对象或对象指针，希望在for_each打印时，调用类自己提供的打印函数
class Person{
public:
	Person(int age, int id) {
		this->age = age;
		this->id = id;
	}
	void show() {
		cout << "成员函数 show()" << endl;
		cout << "age=" << age << endl;
	}
public:
	int age;
	int id;
};

//现在我要调用person里的show()，格式&类名::函数名
void test3() {
	vector<Person> v1;
	Person p1(24, 1), p2(26, 2), p3(25, 3);
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	for_each(v1.begin(), v1.end(), mem_fun_ref(&Person::show));//mem_fun_ref

	cout << endl;
	vector<Person*> v2;
	Person p4(24, 1), p5(26, 2), p6(25, 3);
	v2.push_back(&p4);
	v2.push_back(&p5);
	v2.push_back(&p6);
	for_each(v2.begin(), v2.end(), mem_fun(&Person::show));//mem_fun

	//区别：
	//容器内为*对象*时用//mem_fun_ref
	//容器内为*指针*时用mem_fun
}

int main(void){
	//test0();//绑定适配器
	//test1();//取反适配器 not1 not2
	//test2();//仿函数适配器 ptr_fun
	test3();//成员函数适配器 mem_fun mem_fun_ref

	system("pause");
	return 0;
}
//只有适配仿函数时，才需要继承父类加const，其他不用，也没地方加，可以套用
//for_each(v.begin(), v.end(), bind2nd(ptr_fun(Myprint03), 10));
//这里Myprint03是个普通函数
//vector<int>::iterator it = find_if(v.begin(), v.end(), not1(Mygreater5()));
//这里Mygreater5()是个函数对象