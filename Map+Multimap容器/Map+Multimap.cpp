#include <map>
#include <string>
#include <iostream>
using namespace std;

//mapԪ�صĳ�ʼ��/���/����/ɾ����������
void test0(){
	map<int, string> map1;//����������������ͬ��������������һ��Ϊkey���ͣ�����Ϊvalue����
	//�������ַ�ʽ��������������ظ�keyֵ��ô�죿��
	//����1  pair
	//�����жϣ�ǰ���ַ���������
	pair<map<int,string>::iterator,bool> ret1 = map1.insert(pair<int, string>(1, "teacher01"));
	if (ret1.second) {
		cout << "����ɹ�" << endl;
	}
	else {
		cout << "key�ظ����޷�����" << endl;
	}
	pair<map<int, string>::iterator, bool> ret2 = map1.insert(pair<int, string>(1, "teacher01"));
	if (ret2.second) {
		cout << "����ɹ�" << endl;
	}
	else {
		cout << "key�ظ����޷�����" << endl;
	}
	map1.insert(pair<int, string>(2, "teacher02"));

	//����2  make_pair
	map1.insert(make_pair(3, "teacher04"));
	map1.insert(make_pair(4, "teacher05"));

	//����3 value_type����
	map1.insert(map<int, string>::value_type(5, "teacher05"));
	map1.insert(map<int, string>::value_type(6, "teacher06"));

	//����4***�ص� �������鷽ʽ����
	map1[7] = "teacher07";
	map1[8] = "teacher08";
	map1[8] = "newteacher08";//�������keyֵ�ظ����Ḳ��ǰ���ֵ��
	//�������һ�������ڵĽڵ㣬map���Զ������ýڵ㣬��Ϊ��value��ʼ��Ĭ��ʵֵ0

	//map1['z'] = "teacher08";

	//�����ı���
	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++){
		//*itȡ��������pair
		cout << "key = " << it->first << " " << "value = " << it->second << endl;
	}
	cout << endl;

	//����Ԫ�ص�ɾ��
	while (!map1.empty()){
		map<int, string>::iterator it = map1.begin();
		cout << it->first << "\t" << it->second << endl;
		map1.erase(it);
	}
}

void yichang(){
	map<int, string> map1;
	map1.insert(pair<int, string>(1, "teacher01"));
	map1.insert(pair<int, string>(2, "teacher02"));
	map1.insert(make_pair(3, "teacher04"));
	map1.insert(make_pair(4, "teacher05"));
	map1.insert(map<int, string>::value_type(5, "teacher05"));
	//map1.insert(map<int, string>::value_type(6, "teacher06"));
	//map1[7] = "teacher07";
	//map1[8] = "teacher08";

	//���ҵ���key
	//map�Ĳ��� //�쳣����
	map<int, string>::iterator it2 = map1.find(10);//��setһ����ͬ��֧��lower_bound,upper_bound��equal_range
	if (it2 == map1.end()){
		cout << "key 100 ��ֵ ������" << endl;
	}
	else{
		cout << "---------" << it2->first << "\t" << it2->second << endl;
	}
	//equal_range //�쳣����
	pair<map<int, string>::iterator, map<int, string>::iterator> mypair = map1.equal_range(5); //�������������� �γ�****һ��pair
		//��һ��������lower_bound >= 5�� λ��   //�ڶ���������upper_bound > 5�� λ�� 

	//ʹ�õ�һ��������
	if (mypair.first == map1.end()){
		cout << "��һ�������� >= 5�� λ�� ������" << endl;
	}
	else{
		cout << "---------" << mypair.first->first << "\t" << mypair.first->second << endl;
	}
	//ʹ�õڶ���������
	if (mypair.second == map1.end()){
		cout << "�ڶ��������� > 5�� λ�� ������" << endl;
	}
	else{
		cout << "---------" << mypair.second->first << "\t" << mypair.second->second << endl;
	}

}

//��keyΪ����ʱ
class Mykey{
public:
	Mykey(int id, string name) {
		m_iID = id;
		m_sName = name;
	}
public:
	int m_iID;
	string m_sName;
};

struct mycompare{
	bool operator()(Mykey k1,Mykey k2) {
		return k1.m_iID < k2.m_iID;
	}
};

void test2() {
	map<Mykey, int, mycompare> m;
	m.insert(make_pair(Mykey(1703, "����"), 16));
	m.insert(make_pair(Mykey(1701, "������"), 19));
	m.insert(make_pair(Mykey(1700, "���ǳ�"), 21));
	m.insert(make_pair(Mykey(1706, "�ܽ���"), 16));

	for (map<Mykey, int, mycompare>::iterator it = m.begin(); it != m.end(); it++) {
		cout << " ID = " << it->first.m_iID << " Name = " << it->first.m_sName <<" int:" << it->second << endl;
	}
}

//int main(void){
//	//test0();
//	//yichang();
//	test2();
//
//	system("pause");
//	return 0;
//}