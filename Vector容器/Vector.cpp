#include<iostream>
#include<vector>
using namespace std;

//vector的遍历
void printV(vector<int> &v)
{
	//正向遍历
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	////逆向遍历
	//for (vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); rit++){
	//	cout << *rit << " ";
	//}
	cout << endl;
}

////vector的遍历 通过数组的方式 
//void main33(){
//	vector<int> v1(10);   //提前把内存准备好
//	for (int i = 0; i<10; i++){
//		v1[i] = i + 1;
//	}
//
//	// for (int i=0; i<10; i++){
//	// 	printf("%d ", v1[i]);
//	// }
//	printV(v1);
//}

//vector的初始化
void chushihua()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	int arr[] = {10,20,30,40};
	vector<int> v2(arr, arr + sizeof(arr) / sizeof(int));
	vector<int> v3(v2.begin(),v2.end());
	vector<int> v4(v3);
	vector<int> v5(3,6);

	printV(v1);
	printV(v2);
	printV(v3);
	printV(v4);
	printV(v5);
}

//vector的赋值
void fuzhi() {
	//方式一：构造函数
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));//默认构造
	//方式二：成员方法
	vector<int> v2;
	v2.assign(v1.begin(), v1.end());//v1的头到尾拷贝给v2
	//方式三：重载 =
	vector<int> v3;
	v3 = v2;

	printV(v1);
	printV(v2);
	printV(v3);
	
	//*方式四：swap
	int arr0[] = { 1,2,3,4 };
	vector<int> v4(arr0, arr0 + sizeof(arr0) / sizeof(int));
	printV(v1);
	printV(v4);
	cout << "--------------" << endl;
	v4.swap(v1);
	printV(v1);
	printV(v4);
}

//vector的大小操作
void daxiao() {
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));//默认构造
	//元素个数
	cout << "size = " << v1.size() << endl;
	if (v1.empty()) {
		cout << "空！" << endl;
	}
	else {
		cout << "不空！" << endl;
	}

	v1.resize(2);//如果传的值比v1小，强制扔掉后面的；如果传的值比v1大，size()会被改变成值
	v1.resize(6,1);//默认值1填充
	printV(v1);
	//容量
	cout << "capacity = " << v1.capacity() << endl;//size不能大于capacity
}

//vector存取数据
void cunqu() {
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));//默认构造

	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << " ";//at会抛异常，安全。而重载[]不抛
	}
	cout << endl;

	cout << v1.front() << endl;//返回第一个元素，而v1.begin()返回第一个元素位置
	cout << v1.back() << endl;
}

//vector的插入删除
void charushanchu() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	//头部插入法
	v.insert(v.begin(),30);
	//第三个位置，vector支持随机访问，才可以跳任何位置+5 -3，不支持只能+1，一般支持数组下标的都支持
	v.insert(v.begin() + 2, 100);
	v.insert(v.end(), 40);
	printV(v);

	//删除
	v.erase(v.begin() + 1);//指定位置v.begin()+1
	v.erase(v.begin(),v.end() - 1);//指定范围0~v.end() - 1
	printV(v);

	v.clear();//清空容器
	cout << "size = " << v.size() << endl;
}

//巧用swap收缩capacity空间
void shousuo() {
	vector<int> v;
	for (int i = 0; i < 1000; i++) {
		v.push_back(i);
	}
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;//capacity()在扩大时会大于size，造成浪费，理想状态是相等。

	v.resize(10);
	cout << "---" << endl;
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;

	//收缩内存空间，保证不浪费空间
	vector<int>(v).swap(v);
	cout << "---" << endl;
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
}

//reserve()和resize()区别
void testreserve() {
	//reserve()预留空间
	int num = 0;
	int* address = NULL;
	vector<int> v;
	v.reserve(10000);//如果你明确知道容器里需要申请多少个空间，可以选择提前预留相应数量的空间。好处：不需要进行容器拷贝，减少开销。   不然，像10000个位置要重新拷贝24次。。第24次要拷贝接近一万个数据，开销可想而知。
	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
		if (address != &(v[0])) {
			address = &(v[0]);//拿到第一个元素的地址
			num++;
		}
	}
	cout << "num = " << num << endl;
}

//push_back的强化记忆
void main34()
{
	vector<int> v1(10,2);   //提前把内存准备好
	v1.push_back(100);
	v1.push_back(200);
	cout << "size: " << v1.size() << endl;
	printV(v1);
}
//1迭代器 end()的理解 
//   1	 3	5
//	 ▲	
//			  ▲
//当 it == v1.end()的时候 说明这个容器已经遍历完毕了...
//end()的位置 应该是 5的后面

//2 迭代器的种类
/*
typedef iterator pointer;
typedef const_iterator const_pointer;
typedef _STD reverse_iterator<iterator> reverse_iterator;
typedef _STD reverse_iterator<const_iterator> const_reverse_iterator;
*/

int main(void) {
	//chushihua();
	//fuzhi();
	//daxiao();
	//cunqu();
	//charushanchu();
	//shousuo();
	testreserve();
	//main34();

	system("pause");
	return 0;
}
