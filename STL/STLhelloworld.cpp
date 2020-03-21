#include<iostream>
#include<vector>//��̬����  �ɱ�����
#include<algorithm>
using namespace std;

//for_each���������������ص�����
void printVectorCallback(int v) {//����Ĳ�����vector<int>����Ķ�������һ��
	cout << v << " ";
}

//STL�����﷨  ���� �㷨 ������
void test0() {
	//����һ�������������ƶ�����Ԫ�ش������Ϊint
	vector<int> v;
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	//ͨ��STL�ṩ��for_each()�㷨���б���
	//�����ṩ�ĵ�����
	vector<int>::iterator pBegin = v.begin();//���صĵ��������ͣ�pBeginָ���һ��
	vector<int>::iterator pEnd = v.end();//pEndָ�����һ������һ��

	//�����п��ܴ�Ż����������ͣ�Ҳ���ܴ���Զ����������ͣ����Ա���ʱ��Ҫ�����������ص�ȥ��ӡ
	for_each(pBegin, pEnd, printVectorCallback);//�㷨
}



//����Ҳ���Դ���Զ�����������
class person {
public:
	person(int age, int id) :m_iAge(age), m_iId(id) {}
public:
	int m_iAge;
	int m_iId;
};

void test1() {
	//������������ָ��person����Ԫ��
	vector<person> vp;
	person p1(10, 20), p2(30, 40), p3(50, 60);

	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);

	//�����õ��������б���
	for (vector<person>::iterator it = vp.begin();  it != vp.end(); it++) {
		//�����*it���Ǹ�person����
		cout << (*it).m_iAge << " ";
	}
}

//int main(void) {
//	test0();
//	cout << endl;
//	test1();
//	system("pause");
//	return 0;
//}