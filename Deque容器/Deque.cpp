#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

//deque的遍历
void printD(deque<int> &d){
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

//deque的初始化
void chushihua(){
	deque<int> d1;
	d1.push_back(1);//尾插
	d1.push_back(3);
	d1.push_back(5);
	d1.push_front(-11);//头插
	d1.push_front(-33);
	d1.push_front(-55);
	d1.pop_front();
	d1.pop_back();
	deque<int> d2(10, 6);//10个6
	deque<int> d3(d2.begin(), d2.end());
	deque<int> d4(d3);
	printD(d1);
	cout << "d1头部元素:" << d1.front() << endl;
	cout << "d1尾部元素:" << d1.back() << endl;
	printD(d2);
	printD(d3);
	printD(d4);
}

//deque的赋值 大小操作
void fuzhidaxiao() {
	deque<int> d1;
	deque<int> d2;
	deque<int> d3;
	d1.assign(10, 8);//10个8
	d2.assign(d1.begin(), d1.end());//区间赋值
	d3 = d3;//重载 =

	d1.swap(d2);//交换两个空间元素
	if (d1.empty()) {
		cout << "空！" << endl;
	}
	else {
		cout << "size = " << d1.size() << endl;
	}

	d1.resize(5);//后面5个元素扔掉
}

//deque插入删除
void charushanchu() {
	deque<int> d1;
	d1.push_back(1);//尾插
	d1.push_back(2);
	d1.push_front(3);//头插
	d1.push_front(4);
	d1.push_front(5);

	d1.pop_front();//弹5
	d1.pop_back();//弹2
	printD(d1);

	d1.insert(d1.begin(),200);//一参：位置，二参：值
	d1.insert(d1.begin() + 2, 100);//支持随机访问
	printD(d1);
}

//int main(void){
//	//chushihua();
//	//fuzhidaxiao();
//	charushanchu();
//
//	system("pause");
//	return 0;
//}