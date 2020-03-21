#include <queue>
#include <iostream>
using namespace std;

//��������
void test()
{
	queue<int>  q1;//�޲ι���
	q1.push(1);
	q1.push(2);
	q1.push(3);

	cout << "��ͷԪ��:" << q1.front() << endl;
	cout << "��βԪ��:" << q1.back() << endl;
	cout << "���еĴ�С:" << q1.size() << endl;
	queue<int>  q2(q1);//��������
	while (!q2.empty())
	{
		int tmp = q2.front();
		cout << tmp << " ";
		q2.pop();
	}
}

//���е��㷨 �� �������͵ķ���

//teacher���
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