#include <set>
#include <string>
#include <iostream>
using namespace std;

//��ӡ���
void printSet(set<int> s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//1 ���� ����(Ĭ�ϴ�С����)  Ψһ (��ڶ����� �������ݽṹ�ı���) 
void test(){
	set<int> s1;
	set<int> s2;
	for (int i = 0; i<5; i++)
	{
		int tmp = rand();
		s1.insert(tmp);//�Ӽ������ֵ
	}
	s1.insert(100);
	s2 = s1;
	printSet(s1);
	printSet(s2);

	//ɾ��
	s1.erase(s1.begin());//ɾͷ
	s1.erase(100);//ɾ100
	printSet(s1);
	s2.clear();
	if (s2.empty()) {
		cout << "s2.size = " << s2.size() << endl;
	}
}

//***Set����***
void find() {
	//1 find()����ʵ��ֵ
	set<int> s1;
	for (int i = 0; i<5; i++)
	{
		int tmp = rand();
		s1.insert(tmp);//�Ӽ������ֵ
	}
	s1.insert(1000);
	printSet(s1);

	set<int>::iterator it1 = s1.find(1000);//����ҵ����᷵��һ�������������Ҫ�õ��������ͽ��գ����û�ҵ�������end()
	if (it1 == s1.end()) {
		cout << "û�ҵ���" << endl;
	}
	else {
		cout << "ʵ��ֵ = " << *it1 << endl;
	}

	//2 lower_bound ���ص�һ�����ڵ��ڴ����Ԫ��  ������
	set<int>::iterator it2 = s1.lower_bound(6334);
	if (it2 == s1.end()) {
		cout << "û�ҵ���" << endl;
	}
	else {
		cout << "ʵ��ֵ = " << *it2 << endl;
	}

	//3 upper_bound ���ص�һ�����ڴ����Ԫ��  ������
	set<int>::iterator it3 = s1.upper_bound(6334);
	if (it3 == s1.end()) {
		cout << "û�ҵ���" << endl;
	}
	else {
		cout << "ʵ��ֵ = " << *it3 << endl;
	}

	//4 equal_range ���� lower_bound �� upper_bound ��ֵ������ֵ��pair<set<int>::iterator,set<int>::iterator>
	pair<set<int>::iterator,set<int>::iterator> myit =  s1.equal_range(6334);// [beg, end)
	//myit.first;//�õ���һ��
	//myit.second;
	if(myit.first == s1.end()) {
		cout << "firstû�ҵ���" << endl;
	}
	else {
		cout << "first = " << *myit.first << endl;
	}
	if (myit.second == s1.end()) {
		cout << "secondû�ҵ���" << endl;
	}
	else {
		cout << "second = " << *myit.second << endl;
	}
}

//3 �Զ����������� ����
//03 �º��� �������� ����() ���� ���бȽϴ�С
//��Ŀ��ѧ������ѧ�ţ��������ԣ���Ҫ��������뼸��ѧ������set�����У�
//ʹ�������е�ѧ����ѧ�ŵ���������
class Student{
public:
	Student(string name, int age){
		string m_sName = name;
		m_iAge = age;
	}
public:
	string m_sName;
	int m_iAge;
};

//��������
struct StuFunctor
{
	bool operator()(const Student &left, const Student &right)
	{
		return (left.m_iAge< right.m_iAge);
	}
};

//��ѧ������set���������䲻���ظ������Զ��Ӵ�С������������ȥ���Ƕ������set��֪����ô����Ҫ��StuFunctor�ṹ�����������򷽷�����Ϊset<Student, StuFunctor>ģ��ĵڶ�������
void teststu()
{
	set<Student, StuFunctor> set1;
	Student s1("��1", 32);
	set1.insert(s1);
	set1.insert(Student("��2", 30));
	set1.insert(Student("��3", 53));
	set1.insert(Student("��4", 34));

	//��ӡ���
	for (set<Student, StuFunctor>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << (*it).m_iAge << " ";
	}
}

//int main(void){
//	//test();
//	//find();
//	teststu();
//
//	system("pause");
//	return 0;
//}