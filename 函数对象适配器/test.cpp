#include <string>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <functional>//�ڽ�����
#include <iostream>
using namespace std;

//�º��������� bind1stbind2nd
//�º��������� not1 not2
//�º��������� ptr_fun.
//��Ա���������� mem_fun mem_fun_ref

struct  Myprint01: public binary_function<int,int,void>//���밴�����Ҫ��̳�һ������binary_function<int,int,void>��һ���������ش������������
{
	void operator()(int v,int val) const {//�����뵽������ഫ��һ������int val ��һ��v+val�����ǲ����У���Ϊfor_eachֻ�ܽ�һ�����������Ҫ��������ת��һ������
		//�ģ����밴��Ҫ�����const
		cout << "v= " << v << " val= " << val;
		cout << " v+val= " << v + val <<" "<< endl;
	}
};

//��������
void test0() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	//һ������������ϣ����������ֵÿ������һ��val
	for_each(v.begin(), v.end(),bind2nd(Myprint01(),100));
	//bind2nd��һ����Ԫ��������ת����һԪ��������
	cout << endl;
	//bind1st��bind2nd��ʲô����
	for_each(v.begin(), v.end(), bind1st(Myprint01(), 100));
    //bind1st����addnum��Ϊ���������һ��
	//bind2nd����addnum��Ϊ��������Ķ���
}


//��С����
struct  Mycompare : public binary_function<int, int, bool>
{
	bool operator()(int v1, int v2) const {//��Ԫν��
		return v1 < v2;
	}
};

struct  Myprint02
{
	void operator()(int v) {
		cout << v << " ";
	}
};

//�ұ�5С�ĵ�һ������Ҫ������ı���������
struct  Mygreater5 : public unary_function<int, bool>
{
	bool operator()(int v1) const {//һԪν��
		return v1 > 5;//��5��
	}
};

//ȡ�������� not1 not2
void test1() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(rand() % 100);
	}
	for_each(v.begin(), v.end(), Myprint02());
	cout << endl;
	sort(v.begin(), v.end(), not2(Mycompare()));//�����ϣ��������Myprint02���ı�����˳�򣬾�Ҫ�������not2����Ԫν�ʣ���ͬʱΪ���μ�public binary_function<int, int, bool>
	for_each(v.begin(), v.end(), Myprint02());
	cout << endl;

	//not1��not2��ʲô����
	//�Զ�Ԫν��ȡ������not2  binary_function
	//��һԪν��ȡ������not1  unary_function
	vector<int>::iterator it = find_if(v.begin(), v.end(), not1(Mygreater5()));
	if (it == v.end()) {
		cout << "δ�ҵ���5С����" << endl;
	}
	else {
		cout << *it << endl;
	}
}

//��ͨ����
void Myprint03(int v1, int v2) {
	cout << v1 << " "<<  v2 << " " << endl;
}

//�º��������� ptr_fun
void test2() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(rand() % 100);
	}
	//���⣺��ʱ���Ǻ�������,***��ʱ����Ҫ�������������
	//��Ҫ����ͨ���� ת�� �������� ptr_fun
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(Myprint03), 10));//����ptr_fun()ת���ɺ�����������bind2nd()���һ������
}


//��Ա���������� mem_fun mem_fun_ref
//��������д�ŵ��Ƕ�������ָ�룬ϣ����for_each��ӡʱ���������Լ��ṩ�Ĵ�ӡ����
class Person{
public:
	Person(int age, int id) {
		this->age = age;
		this->id = id;
	}
	void show() {
		cout << "��Ա���� show()" << endl;
		cout << "age=" << age << endl;
	}
public:
	int age;
	int id;
};

//������Ҫ����person���show()����ʽ&����::������
void test3() {
	vector<Person> v1;
	Person p1(24, 1), p2(26, 2), p3(25, 3);
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	for_each(v1.begin(), v1.end(), mem_fun_ref(&Person::show));//mem_fun_ref

	cout << endl;
	vector<Person*> v2;
	Person p4(24, 1), p5(26, 2), p6(25, 3);
	v2.push_back(&p4);
	v2.push_back(&p5);
	v2.push_back(&p6);
	for_each(v2.begin(), v2.end(), mem_fun(&Person::show));//mem_fun

	//����
	//������Ϊ*����*ʱ��//mem_fun_ref
	//������Ϊ*ָ��*ʱ��mem_fun
}

int main(void){
	//test0();//��������
	//test1();//ȡ�������� not1 not2
	//test2();//�º��������� ptr_fun
	test3();//��Ա���������� mem_fun mem_fun_ref

	system("pause");
	return 0;
}
//ֻ������º���ʱ������Ҫ�̳и����const���������ã�Ҳû�ط��ӣ���������
//for_each(v.begin(), v.end(), bind2nd(ptr_fun(Myprint03), 10));
//����Myprint03�Ǹ���ͨ����
//vector<int>::iterator it = find_if(v.begin(), v.end(), not1(Mygreater5()));
//����Mygreater5()�Ǹ���������