#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

//string的初始化
void chushihua()
{
	string s1 = "aaaa";
	string s2("bbbb");
	string s3(s2); //通过拷贝构造函数 来初始化对象s3
	string s4(10, 'a');
	string s5 = s4;

	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	cout << "s3:" << s3 << endl;
	cout << "s4:" << s4 << endl;
	cout << "s5:" << s5 << endl;
}

//string的 遍历
void bianli()
{
	string s1 = "abcdefg";

	//1 数组方式  
	for (int i = 0; i<s1.size(); i++)
	{
		cout << s1[i] << " ";//[]如果访问越界，就直接荡掉了
	}
	cout << endl;

	//2 迭代器
	for (string::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	try//用at越界时会抛出异常outofrange
	{
		for (int i = 0; i<s1.size() + 3; i++)
		{
			cout << s1.at(i) << " ";  //抛出异常
		}
	}
	catch (...)
	{
		cout << "发生异常\n";
	}
	cout << "at之后" << endl;
}

//字符串的 连接  三种方式
void pingjie()
{
	string s1 = "aaa";
	string s2 = "bbb";
	//s1 += s2;//提供了+=重载
	s1 = s1 + s2;
	cout << "s1:" << s1 << endl;

	string s3 = "333";
	string s4 = "444";
	s3.append(s4);//s4追加到s3尾部
	cout << "s3:" << s3 << endl;
}

//string查找
void chazhao()
{
	string s1 = "wbm hello wbm 111  wbm 222  wbm 333 ";
	//			  ▲
	//第一次 出现wbm index
	int index0 = s1.rfind("wbm"); //位置下标 从最后一个位置开始
	int index1 = s1.find("wbm"); //位置下标 从0开始
	int index2 = s1.find("z", 4); //位置下标 指定从4开始
	cout << "index0: " << index0 << endl;
	cout << "index1: " << index1 << endl;
	cout << "index2: " << index2 << endl;//找不到就会返回-1
}


void replaceall(string s) {
	int offindex = s.find("wbm");
	if (offindex != -1) {
		s.replace(offindex, 3, "WBM");
		cout << s << "***";
		replaceall(s);
	}
}
//字符串的替换  find从前往后找，找到第一次出现的位置，rfind从后往前找
void tihuan() {
	//string s3 = "aaa bbb ccc";
	//s3.replace(0, 3, "AAA");
	//cout << "s3" << s3 << endl;

	string s1 = "wbm hello wbm 111  wbm 222  wbm 333 ";
	string s2 = "wbm hello wbm 111  wbm 222  wbm 333 ";
	//案例2  把第一个小写wbm===>WBM
	int offindex = s1.find("wbm");
	s1.replace(offindex, 3, "WBM");
	cout << "s1替换后的结果: " << s1 << endl;
	//案例3  把所有小写wbm===>WBM
	replaceall(s2);
	cout << "s2全部替换后的结果: " << s2 << endl;//回溯??????????
}

//字符串比较  大于返回1，小于返回-1，等于返回0
void compare() {  
	string s1 = "hello1 hello2 hello1";
	string s2 = "hello1 hello2 hello3";
	if (s1.compare(s2) == 0) {
		cout << "s1 = s2" << endl;
	}
	else
	{
		cout << "s1 ≠ s2" << endl;
	}
}

//截取字符串（子串）
void jiequ() {
	string s1 = "asfhoqebobv";
	string mys = s1.substr(1, 3);
	cout <<"mys:"<< mys << endl;
}

//截断（区间删除）和插入
void charushanchu()
{
	string s1 = "hello1 hello2 hello1";
	s1.insert(3,"fxxk");//在哪个位置插入？插入什么字符串？
	s1.erase(0,2);//从哪个位置删？删到哪个位置？
	cout << s1 << endl;

	//string::iterator it = find(s1.begin(), s1.end(), 'l');
	//if (it != s1.end())
	//{
	//	s1.erase(it);
	//}
	//cout << "s1删除l以后的结果:" << s1 << endl;

	//s1.erase(s1.begin(), s1.end());
	//cout << "s1全部删除:" << s1 << endl;
	//cout << "s1长度 " << s1.length() << endl;

	//string s2 = "BBB";

	//s2.insert(0, "AAA"); // 头插法
	//s2.insert(s2.length(), "CCC");

	//cout << s2 << endl;
}

//字符指针和string的转换
//void main23()
//{
//	string s1 = "aaabbbb";
//
//	//1 s1===>char *
//	//printf("s1:%s \n", s1.c_str());
//
//	//2 char *====>sting 
//
//
//	//3 s1的内容 copy buf中
//	//char buf1[128] = {0};
//	//s1.copy(buf1, 3, 0);  //注意 只给你copy3个字符 不会变成C风格的字符串
//	//cout << "buf1:" << buf1 << endl; 
//}

void daxiaoxie()
{
	string s1 = "AAAbbb";
	//1函数的入口地址 2函数对象 3预定义的函数对象
	transform(s1.begin(), s1.end(), s1.begin(), toupper);
	cout << "s1:" << s1 << endl;

	string s2 = "AAAbbb";
	transform(s2.begin(), s2.end(), s2.begin(), tolower);
	cout << "s2:" << s2 << endl;
}

int main(void)
{
	//chushihua();
	//bianli();
	//pingjie();
	//chazhao();
	//tihuan();
	//compare();
	//jiequ();
	//charushanchu();
	daxiaoxie();

	system("pause");
	return 0;
}