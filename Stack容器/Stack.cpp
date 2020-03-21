#include <iostream>
#include <stack>
using namespace std;

//栈模型 
//栈的算法 和 数据类型的分离
void test()
{
	//初始化
	stack<int> s1;//泛型编程
	stack<int> s2(s1);

	//入栈
	for (int i = 0; i<10; i++)
	{
		s1.push(i + 1);
	}
	cout << "栈的大小" << s1.size() << endl;
	//打印stack数据（无迭代器，只能用弹栈方式打印）
	//出栈
	while (!s1.empty())
	{
		int tmp = s1.top(); //获取栈顶元素
		cout << tmp << " ";
		s1.pop(); //弹出栈顶元素 
	}
}

//teacher结点
class Teacher{
public:
	void printT()
	{
		cout << "age:" << age << endl;
	}
public:
	int		age;
	char	name[32];
};

//stack存放对象
void testteacher(){
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	stack<Teacher> s;
	s.push(t1);
	s.push(t2);
	s.push(t3);

	while (!s.empty())
	{
		Teacher tmp = s.top();
		tmp.printT();
		s.pop();
	}
}

//stack存放对象指针
void testteacheradd()
{
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	stack<Teacher *> s;
	s.push(&t1);
	s.push(&t2);
	s.push(&t3);

	while (!s.empty())
	{
		Teacher *p = s.top();
		p->printT();
		s.pop();
	}
}

int main(void){
	//test();
	//testteacher();
	testteacheradd();

	system("pause");
	return 0;
}