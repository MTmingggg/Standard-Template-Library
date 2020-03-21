#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

//deque�ı���
void printD(deque<int> &d){
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

//deque�ĳ�ʼ��
void chushihua(){
	deque<int> d1;
	d1.push_back(1);//β��
	d1.push_back(3);
	d1.push_back(5);
	d1.push_front(-11);//ͷ��
	d1.push_front(-33);
	d1.push_front(-55);
	d1.pop_front();
	d1.pop_back();
	deque<int> d2(10, 6);//10��6
	deque<int> d3(d2.begin(), d2.end());
	deque<int> d4(d3);
	printD(d1);
	cout << "d1ͷ��Ԫ��:" << d1.front() << endl;
	cout << "d1β��Ԫ��:" << d1.back() << endl;
	printD(d2);
	printD(d3);
	printD(d4);
}

//deque�ĸ�ֵ ��С����
void fuzhidaxiao() {
	deque<int> d1;
	deque<int> d2;
	deque<int> d3;
	d1.assign(10, 8);//10��8
	d2.assign(d1.begin(), d1.end());//���丳ֵ
	d3 = d3;//���� =

	d1.swap(d2);//���������ռ�Ԫ��
	if (d1.empty()) {
		cout << "�գ�" << endl;
	}
	else {
		cout << "size = " << d1.size() << endl;
	}

	d1.resize(5);//����5��Ԫ���ӵ�
}

//deque����ɾ��
void charushanchu() {
	deque<int> d1;
	d1.push_back(1);//β��
	d1.push_back(2);
	d1.push_front(3);//ͷ��
	d1.push_front(4);
	d1.push_front(5);

	d1.pop_front();//��5
	d1.pop_back();//��2
	printD(d1);

	d1.insert(d1.begin(),200);//һ�Σ�λ�ã����Σ�ֵ
	d1.insert(d1.begin() + 2, 100);//֧���������
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