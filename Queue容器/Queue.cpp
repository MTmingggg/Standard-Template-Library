#include <queue>
#include <iostream>
using namespace std;

//基本操作
void test()
{
	queue<int>  q1;//无参构造
	q1.push(1);
	q1.push(2);
	q1.push(3);

	cout << "队头元素:" << q1.front() << endl;
	cout << "队尾元素:" << q1.back() << endl;
	cout << "队列的大小:" << q1.size() << endl;
	queue<int>  q2(q1);//拷贝构造
	while (!q2.empty())
	{
		int tmp = q2.front();
		cout << tmp << " ";
		q2.pop();
	}
}

//队列的算法 和 数据类型的分离

//teacher结点
class Teacher
{
public:
	void printT(){
		cout << "age:" << age << endl;
	}
public:
	int		age;
	char	name[32];
};

void testteacher()
{
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	queue<Teacher> q;
	q.push(t1);
	q.push(t2);
	q.push(t3);

	while (!q.empty())
	{
		Teacher tmp = q.front();
		tmp.printT();
		q.pop();
	}
}

void testteacheradd()
{
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	queue<Teacher *> q;
	q.push(&t1);
	q.push(&t2);
	q.push(&t3);

	while (!q.empty())
	{
		Teacher *tmp = q.front();
		tmp->printT();
		q.pop();
	}
}

int main(void){
	test();
	testteacher();
	testteacheradd();
	
	system("pause");
	return 0;
}