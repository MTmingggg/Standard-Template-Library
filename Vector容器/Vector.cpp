#include<iostream>
#include<vector>
using namespace std;

//vector�ı���
void printV(vector<int> &v)
{
	//�������
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	////�������
	//for (vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); rit++){
	//	cout << *rit << " ";
	//}
	cout << endl;
}

////vector�ı��� ͨ������ķ�ʽ 
//void main33(){
//	vector<int> v1(10);   //��ǰ���ڴ�׼����
//	for (int i = 0; i<10; i++){
//		v1[i] = i + 1;
//	}
//
//	// for (int i=0; i<10; i++){
//	// 	printf("%d ", v1[i]);
//	// }
//	printV(v1);
//}

//vector�ĳ�ʼ��
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

//vector�ĸ�ֵ
void fuzhi() {
	//��ʽһ�����캯��
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));//Ĭ�Ϲ���
	//��ʽ������Ա����
	vector<int> v2;
	v2.assign(v1.begin(), v1.end());//v1��ͷ��β������v2
	//��ʽ�������� =
	vector<int> v3;
	v3 = v2;

	printV(v1);
	printV(v2);
	printV(v3);
	
	//*��ʽ�ģ�swap
	int arr0[] = { 1,2,3,4 };
	vector<int> v4(arr0, arr0 + sizeof(arr0) / sizeof(int));
	printV(v1);
	printV(v4);
	cout << "--------------" << endl;
	v4.swap(v1);
	printV(v1);
	printV(v4);
}

//vector�Ĵ�С����
void daxiao() {
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));//Ĭ�Ϲ���
	//Ԫ�ظ���
	cout << "size = " << v1.size() << endl;
	if (v1.empty()) {
		cout << "�գ�" << endl;
	}
	else {
		cout << "���գ�" << endl;
	}

	v1.resize(2);//�������ֵ��v1С��ǿ���ӵ�����ģ��������ֵ��v1��size()�ᱻ�ı��ֵ
	v1.resize(6,1);//Ĭ��ֵ1���
	printV(v1);
	//����
	cout << "capacity = " << v1.capacity() << endl;//size���ܴ���capacity
}

//vector��ȡ����
void cunqu() {
	int arr[] = { 10,20,30,40 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));//Ĭ�Ϲ���

	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << " ";//at�����쳣����ȫ��������[]����
	}
	cout << endl;

	cout << v1.front() << endl;//���ص�һ��Ԫ�أ���v1.begin()���ص�һ��Ԫ��λ��
	cout << v1.back() << endl;
}

//vector�Ĳ���ɾ��
void charushanchu() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	//ͷ�����뷨
	v.insert(v.begin(),30);
	//������λ�ã�vector֧��������ʣ��ſ������κ�λ��+5 -3����֧��ֻ��+1��һ��֧�������±�Ķ�֧��
	v.insert(v.begin() + 2, 100);
	v.insert(v.end(), 40);
	printV(v);

	//ɾ��
	v.erase(v.begin() + 1);//ָ��λ��v.begin()+1
	v.erase(v.begin(),v.end() - 1);//ָ����Χ0~v.end() - 1
	printV(v);

	v.clear();//�������
	cout << "size = " << v.size() << endl;
}

//����swap����capacity�ռ�
void shousuo() {
	vector<int> v;
	for (int i = 0; i < 1000; i++) {
		v.push_back(i);
	}
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;//capacity()������ʱ�����size������˷ѣ�����״̬����ȡ�

	v.resize(10);
	cout << "---" << endl;
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;

	//�����ڴ�ռ䣬��֤���˷ѿռ�
	vector<int>(v).swap(v);
	cout << "---" << endl;
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
}

//reserve()��resize()����
void testreserve() {
	//reserve()Ԥ���ռ�
	int num = 0;
	int* address = NULL;
	vector<int> v;
	v.reserve(10000);//�������ȷ֪����������Ҫ������ٸ��ռ䣬����ѡ����ǰԤ����Ӧ�����Ŀռ䡣�ô�������Ҫ�����������������ٿ�����   ��Ȼ����10000��λ��Ҫ���¿���24�Ρ�����24��Ҫ�����ӽ�һ������ݣ����������֪��
	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
		if (address != &(v[0])) {
			address = &(v[0]);//�õ���һ��Ԫ�صĵ�ַ
			num++;
		}
	}
	cout << "num = " << num << endl;
}

//push_back��ǿ������
void main34()
{
	vector<int> v1(10,2);   //��ǰ���ڴ�׼����
	v1.push_back(100);
	v1.push_back(200);
	cout << "size: " << v1.size() << endl;
	printV(v1);
}
//1������ end()����� 
//   1	 3	5
//	 ��	
//			  ��
//�� it == v1.end()��ʱ�� ˵����������Ѿ����������...
//end()��λ�� Ӧ���� 5�ĺ���

//2 ������������
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
