#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

//string�ĳ�ʼ��
void chushihua()
{
	string s1 = "aaaa";
	string s2("bbbb");
	string s3(s2); //ͨ���������캯�� ����ʼ������s3
	string s4(10, 'a');
	string s5 = s4;

	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	cout << "s3:" << s3 << endl;
	cout << "s4:" << s4 << endl;
	cout << "s5:" << s5 << endl;
}

//string�� ����
void bianli()
{
	string s1 = "abcdefg";

	//1 ���鷽ʽ  
	for (int i = 0; i<s1.size(); i++)
	{
		cout << s1[i] << " ";//[]�������Խ�磬��ֱ�ӵ�����
	}
	cout << endl;

	//2 ������
	for (string::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	try//��atԽ��ʱ���׳��쳣outofrange
	{
		for (int i = 0; i<s1.size() + 3; i++)
		{
			cout << s1.at(i) << " ";  //�׳��쳣
		}
	}
	catch (...)
	{
		cout << "�����쳣\n";
	}
	cout << "at֮��" << endl;
}

//�ַ����� ����  ���ַ�ʽ
void pingjie()
{
	string s1 = "aaa";
	string s2 = "bbb";
	//s1 += s2;//�ṩ��+=����
	s1 = s1 + s2;
	cout << "s1:" << s1 << endl;

	string s3 = "333";
	string s4 = "444";
	s3.append(s4);//s4׷�ӵ�s3β��
	cout << "s3:" << s3 << endl;
}

//string����
void chazhao()
{
	string s1 = "wbm hello wbm 111  wbm 222  wbm 333 ";
	//			  ��
	//��һ�� ����wbm index
	int index0 = s1.rfind("wbm"); //λ���±� �����һ��λ�ÿ�ʼ
	int index1 = s1.find("wbm"); //λ���±� ��0��ʼ
	int index2 = s1.find("z", 4); //λ���±� ָ����4��ʼ
	cout << "index0: " << index0 << endl;
	cout << "index1: " << index1 << endl;
	cout << "index2: " << index2 << endl;//�Ҳ����ͻ᷵��-1
}


void replaceall(string s) {
	int offindex = s.find("wbm");
	if (offindex != -1) {
		s.replace(offindex, 3, "WBM");
		cout << s << "***";
		replaceall(s);
	}
}
//�ַ������滻  find��ǰ�����ң��ҵ���һ�γ��ֵ�λ�ã�rfind�Ӻ���ǰ��
void tihuan() {
	//string s3 = "aaa bbb ccc";
	//s3.replace(0, 3, "AAA");
	//cout << "s3" << s3 << endl;

	string s1 = "wbm hello wbm 111  wbm 222  wbm 333 ";
	string s2 = "wbm hello wbm 111  wbm 222  wbm 333 ";
	//����2  �ѵ�һ��Сдwbm===>WBM
	int offindex = s1.find("wbm");
	s1.replace(offindex, 3, "WBM");
	cout << "s1�滻��Ľ��: " << s1 << endl;
	//����3  ������Сдwbm===>WBM
	replaceall(s2);
	cout << "s2ȫ���滻��Ľ��: " << s2 << endl;//����??????????
}

//�ַ����Ƚ�  ���ڷ���1��С�ڷ���-1�����ڷ���0
void compare() {  
	string s1 = "hello1 hello2 hello1";
	string s2 = "hello1 hello2 hello3";
	if (s1.compare(s2) == 0) {
		cout << "s1 = s2" << endl;
	}
	else
	{
		cout << "s1 �� s2" << endl;
	}
}

//��ȡ�ַ������Ӵ���
void jiequ() {
	string s1 = "asfhoqebobv";
	string mys = s1.substr(1, 3);
	cout <<"mys:"<< mys << endl;
}

//�ضϣ�����ɾ�����Ͳ���
void charushanchu()
{
	string s1 = "hello1 hello2 hello1";
	s1.insert(3,"fxxk");//���ĸ�λ�ò��룿����ʲô�ַ�����
	s1.erase(0,2);//���ĸ�λ��ɾ��ɾ���ĸ�λ�ã�
	cout << s1 << endl;

	//string::iterator it = find(s1.begin(), s1.end(), 'l');
	//if (it != s1.end())
	//{
	//	s1.erase(it);
	//}
	//cout << "s1ɾ��l�Ժ�Ľ��:" << s1 << endl;

	//s1.erase(s1.begin(), s1.end());
	//cout << "s1ȫ��ɾ��:" << s1 << endl;
	//cout << "s1���� " << s1.length() << endl;

	//string s2 = "BBB";

	//s2.insert(0, "AAA"); // ͷ�巨
	//s2.insert(s2.length(), "CCC");

	//cout << s2 << endl;
}

//�ַ�ָ���string��ת��
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
//	//3 s1������ copy buf��
//	//char buf1[128] = {0};
//	//s1.copy(buf1, 3, 0);  //ע�� ֻ����copy3���ַ� ������C�����ַ���
//	//cout << "buf1:" << buf1 << endl; 
//}

void daxiaoxie()
{
	string s1 = "AAAbbb";
	//1��������ڵ�ַ 2�������� 3Ԥ����ĺ�������
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