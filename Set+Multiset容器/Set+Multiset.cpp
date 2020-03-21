#include <set>
#include <string>
#include <iostream>
using namespace std;

//打印输出
void printSet(set<int> s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//1 集合 有序(默认从小到大)  唯一 (红黑二叉树 这种数据结构的变体) 
void test(){
	set<int> s1;
	set<int> s2;
	for (int i = 0; i<5; i++)
	{
		int tmp = rand();
		s1.insert(tmp);//加几个随机值
	}
	s1.insert(100);
	s2 = s1;
	printSet(s1);
	printSet(s2);

	//删除
	s1.erase(s1.begin());//删头
	s1.erase(100);//删100
	printSet(s1);
	s2.clear();
	if (s2.empty()) {
		cout << "s2.size = " << s2.size() << endl;
	}
}

//***Set查找***
void find() {
	//1 find()查找实际值
	set<int> s1;
	for (int i = 0; i<5; i++)
	{
		int tmp = rand();
		s1.insert(tmp);//加几个随机值
	}
	s1.insert(1000);
	printSet(s1);

	set<int>::iterator it1 = s1.find(1000);//如果找到，会返回一个迭代器，因此要用迭代器类型接收，如果没找到，返回end()
	if (it1 == s1.end()) {
		cout << "没找到！" << endl;
	}
	else {
		cout << "实际值 = " << *it1 << endl;
	}

	//2 lower_bound 返回第一个大于等于传入的元素  迭代器
	set<int>::iterator it2 = s1.lower_bound(6334);
	if (it2 == s1.end()) {
		cout << "没找到！" << endl;
	}
	else {
		cout << "实际值 = " << *it2 << endl;
	}

	//3 upper_bound 返回第一个大于传入的元素  迭代器
	set<int>::iterator it3 = s1.upper_bound(6334);
	if (it3 == s1.end()) {
		cout << "没找到！" << endl;
	}
	else {
		cout << "实际值 = " << *it3 << endl;
	}

	//4 equal_range 返回 lower_bound 和 upper_bound 的值（两个值）pair<set<int>::iterator,set<int>::iterator>
	pair<set<int>::iterator,set<int>::iterator> myit =  s1.equal_range(6334);// [beg, end)
	//myit.first;//拿到第一个
	//myit.second;
	if(myit.first == s1.end()) {
		cout << "first没找到！" << endl;
	}
	else {
		cout << "first = " << *myit.first << endl;
	}
	if (myit.second == s1.end()) {
		cout << "second没找到！" << endl;
	}
	else {
		cout << "second = " << *myit.second << endl;
	}
}

//3 自定义数据类型 排序
//03 仿函数 函数对象 重载() 操作 进行比较大小
//题目：学生包含学号，姓名属性，现要求任意插入几个学生对象到set容器中，
//使得容器中的学生按学号的升序排序
class Student{
public:
	Student(string name, int age){
		string m_sName = name;
		m_iAge = age;
	}
public:
	string m_sName;
	int m_iAge;
};

//函数对象
struct StuFunctor
{
	bool operator()(const Student &left, const Student &right)
	{
		return (left.m_iAge< right.m_iAge);
	}
};

//将学生塞进set容器（年龄不会重复），自动从大到小排序，由于塞进去的是对象，因此set不知道怎么排序，要在StuFunctor结构体中重载排序方法，作为set<Student, StuFunctor>模板的第二个参数
void teststu()
{
	set<Student, StuFunctor> set1;
	Student s1("张1", 32);
	set1.insert(s1);
	set1.insert(Student("张2", 30));
	set1.insert(Student("张3", 53));
	set1.insert(Student("张4", 34));

	//打印输出
	for (set<Student, StuFunctor>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << (*it).m_iAge << " ";
	}
}

//int main(void){
//	//test();
//	//find();
//	teststu();
//
//	system("pause");
//	return 0;
//}