#include <iostream>
#include <stack>
using namespace std;

//ջģ�� 
//ջ���㷨 �� �������͵ķ���
void test()
{
	//��ʼ��
	stack<int> s1;//���ͱ��
	stack<int> s2(s1);

	//��ջ
	for (int i = 0; i<10; i++)
	{
		s1.push(i + 1);
	}
	cout << "ջ�Ĵ�С" << s1.size() << endl;
	//��ӡstack���ݣ��޵�������ֻ���õ�ջ��ʽ��ӡ��
	//��ջ
	while (!s1.empty())
	{
		int tmp = s1.top(); //��ȡջ��Ԫ��
		cout << tmp << " ";
		s1.pop(); //����ջ��Ԫ�� 
	}
}

//teacher���
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

//stack��Ŷ���
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

//stack��Ŷ���ָ��
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