#include <list>
#include <iostream>
using namespace std;

//list�Ļ�������
void test()
{
	list<int> l;
	cout << "list�Ĵ�С:" << l.size() << endl;
	for (int i = 0; i<10; i++)
	{
		l.push_back(i); //β������Ԫ�� β�巨
	}
	cout << "list�Ĵ�С:" << l.size() << endl;

	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//list�����������
	//0	 1	2	3	4	5
	//              ��
	it = l.begin();//0��һ��λ��
	it++;//1�ڶ���λ��
	it++;//2������λ��
	it++;//3���ĸ�λ��
	//it = it + 5;  //��֧������ķ�������
	l.insert(it, 100); //��ʾҪ�ڵ��ĸ�λ���жϣ����룬���100���뵽�˵��ĸ�λ��
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	//����1 ����Ľ��index ����Ǵ�0��λ�ÿ�ʼ
	//��3��λ�ò���Ԫ��, ��ԭ����3��λ�ñ��4��λ��  ԭ����4��λ�ñ��5��λ��
}

//list ɾ��
void shanchu()
{
	list<int> l;
	cout << "list�Ĵ�С:" << l.size() << endl;
	for (int i = 0; i<10; i++)
	{
		l.push_back(i); //β������Ԫ�� β�巨
	}
	cout << "list�Ĵ�С:" << l.size() << endl;

	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//0	 1	2	3	4	5
	//          ��
	list<int>::iterator it1 = l.begin();//0
	list<int>::iterator it2 = l.begin();
	it2++;
	it2++;
	it2++;//3

	l.erase(it1, it2);//ɾ��[0,3)����������ҿ�
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	l.insert(l.begin(), 100);
	l.push_front(1000);
	l.insert(l.end(), 90);
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	l.erase(l.begin()); //ɾ��ͷ�ڵ�
	l.remove(100); //ɾ������ƥ��ֵ��������100
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	l.clear();//�������
}

//list�ĸ�ֵ����
void fuzhi() {
	list<int> l1;
	list<int> l2;
	l1.assign(10, 10);
	l2 = l1;
	l2.swap(l1);
}

//��ת����
void fanzhuan() {
	list<int> l;
	for (int i = 0; i<10; i++)
	{
		l.push_back(i); //β������Ԫ�� β�巨
	}
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	l.reverse();//Ԫ�ط�ת
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

bool mycom(int l1, int l2) {
	return l1 > l2;
}

//List����
void sort() {
	list<int> l;
	l.push_back(9);
	l.push_back(1);
	l.push_back(6);
	l.push_back(3);
	l.push_back(4);

	l.sort();//Ĭ�ϴ�С����
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	l.sort(mycom);//������Զ�������  �Ӵ�С  ���Դ���ص�
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main(void){
	//test();
	//shanchu();
	//fanzhuan();
	sort();

	system("pause");
	return 0;
}