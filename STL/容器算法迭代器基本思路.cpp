#include<iostream>
using namespace std;

//算法 负责统计某个元素的个数,完全对迭代器进行操作
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
//	//数组 容器（非标准）
//	int arr[] = { 0,7,5,9,6,5,1 };
//	
//	//区间，要告诉算法
//	//迭代器 指向容器开始位置（第一个元素）
//	int* pBegin = arr;
//	//迭代器 指向容器结束位置（最后一个元素的下一个）
//	int* pEnd = &(arr[sizeof(arr) / sizeof(int)]);
//
//	int num = mycount(pBegin, pEnd, 5);
//	cout << "num = " << num << endl;
//	system("pause");
//	return 0;
//}