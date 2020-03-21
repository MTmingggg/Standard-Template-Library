#include <list>
#include <iostream>
using namespace std;

//list的基本操作
void test()
{
	list<int> l;
	cout << "list的大小:" << l.size() << endl;
	for (int i = 0; i<10; i++)
	{
		l.push_back(i); //尾部插入元素 尾插法
	}
	cout << "list的大小:" << l.size() << endl;

	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//list不能随机访问
	//0	 1	2	3	4	5
	//              ▲
	it = l.begin();//0第一个位置
	it++;//1第二个位置
	it++;//2第三个位置
	it++;//3第四个位置
	//it = it + 5;  //不支持随机的访问容器
	l.insert(it, 100); //表示要在第四个位置切断，插入，因此100插入到了第四个位置
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	//结论1 链表的结点index 序号是从0号位置开始
	//在3号位置插入元素, 让原来的3号位置变成4号位置  原来的4号位置变成5号位置
}

//list 删除
void shanchu()
{
	list<int> l;
	cout << "list的大小:" << l.size() << endl;
	for (int i = 0; i<10; i++)
	{
		l.push_back(i); //尾部插入元素 尾插法
	}
	cout << "list的大小:" << l.size() << endl;

	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//0	 1	2	3	4	5
	//          ▲
	list<int>::iterator it1 = l.begin();//0
	list<int>::iterator it2 = l.begin();
	it2++;
	it2++;
	it2++;//3

	l.erase(it1, it2);//删除[0,3)！！！左闭右开
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

	l.erase(l.begin()); //删除头节点
	l.remove(100); //删除所有匹配值——所有100
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	l.clear();//清空链表
}

//list的赋值操作
void fuzhi() {
	list<int> l1;
	list<int> l2;
	l1.assign(10, 10);
	l2 = l1;
	l2.swap(l1);
}

//反转链表
void fanzhuan() {
	list<int> l;
	for (int i = 0; i<10; i++)
	{
		l.push_back(i); //尾部插入元素 尾插法
	}
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	l.reverse();//元素反转
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

bool mycom(int l1, int l2) {
	return l1 > l2;
}

//List排序
void sort() {
	list<int> l;
	l.push_back(9);
	l.push_back(1);
	l.push_back(6);
	l.push_back(3);
	l.push_back(4);

	l.sort();//默认从小到大
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	l.sort(mycom);//对象的自定义排序  从大到小  可以传入回调
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