#include<iostream>
using namespace std;

//�㷨 ����ͳ��ĳ��Ԫ�صĸ���,��ȫ�Ե��������в���
int mycount(int* start,int* end,int val) {
	int num = 0;
	while (start != end) {
		if (*start == val) {
			num++;
		}
		start++;
	}
	return num;
}

//int main(void) {
//	//���� �������Ǳ�׼��
//	int arr[] = { 0,7,5,9,6,5,1 };
//	
//	//���䣬Ҫ�����㷨
//	//������ ָ��������ʼλ�ã���һ��Ԫ�أ�
//	int* pBegin = arr;
//	//������ ָ����������λ�ã����һ��Ԫ�ص���һ����
//	int* pEnd = &(arr[sizeof(arr) / sizeof(int)]);
//
//	int num = mycount(pBegin, pEnd, 5);
//	cout << "num = " << num << endl;
//	system("pause");
//	return 0;
//}