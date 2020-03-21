#include <map>
#include <string>
#include <iostream>
using namespace std;

//map元素的初始化/添加/遍历/删除基本操作
void test0(){
	map<int, string> map1;//这里与所有容器不同，参数有两个，一参为key类型，二参为value类型
	//掌握四种方式的区别（如果遇到重复key值怎么办？）
	//方法1  pair
	//这种判断，前三种方法都适用
	pair<map<int,string>::iterator,bool> ret1 = map1.insert(pair<int, string>(1, "teacher01"));
	if (ret1.second) {
		cout << "插入成功" << endl;
	}
	else {
		cout << "key重复，无法插入" << endl;
	}
	pair<map<int, string>::iterator, bool> ret2 = map1.insert(pair<int, string>(1, "teacher01"));
	if (ret2.second) {
		cout << "插入成功" << endl;
	}
	else {
		cout << "key重复，无法插入" << endl;
	}
	map1.insert(pair<int, string>(2, "teacher02"));

	//方法2  make_pair
	map1.insert(make_pair(3, "teacher04"));
	map1.insert(make_pair(4, "teacher05"));

	//方法3 value_type类型
	map1.insert(map<int, string>::value_type(5, "teacher05"));
	map1.insert(map<int, string>::value_type(6, "teacher06"));

	//方法4***重点 类似数组方式访问
	map1[7] = "teacher07";
	map1[8] = "teacher08";
	map1[8] = "newteacher08";//如果出现key值重复，会覆盖前面的值！
	//如果访问一个不存在的节点，map会自动创建该节点，并为该value初始化默认实值0

	//map1['z'] = "teacher08";

	//容器的遍历
	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++){
		//*it取出来的是pair
		cout << "key = " << it->first << " " << "value = " << it->second << endl;
	}
	cout << endl;

	//容器元素的删除
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

	//查找的是key
	//map的查找 //异常处理
	map<int, string>::iterator it2 = map1.find(10);//和set一样，同样支持lower_bound,upper_bound和equal_range
	if (it2 == map1.end()){
		cout << "key 100 的值 不存在" << endl;
	}
	else{
		cout << "---------" << it2->first << "\t" << it2->second << endl;
	}
	//equal_range //异常处理
	pair<map<int, string>::iterator, map<int, string>::iterator> mypair = map1.equal_range(5); //返回两个迭代器 形成****一个pair
		//第一个迭代器lower_bound >= 5的 位置   //第二个迭代器upper_bound > 5的 位置 

	//使用第一个迭代器
	if (mypair.first == map1.end()){
		cout << "第一个迭代器 >= 5的 位置 不存在" << endl;
	}
	else{
		cout << "---------" << mypair.first->first << "\t" << mypair.first->second << endl;
	}
	//使用第二个迭代器
	if (mypair.second == map1.end()){
		cout << "第二个迭代器 > 5的 位置 不存在" << endl;
	}
	else{
		cout << "---------" << mypair.second->first << "\t" << mypair.second->second << endl;
	}

}

//当key为对象时
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
	m.insert(make_pair(Mykey(1703, "周润发"), 16));
	m.insert(make_pair(Mykey(1701, "王祖蓝"), 19));
	m.insert(make_pair(Mykey(1700, "周星驰"), 21));
	m.insert(make_pair(Mykey(1706, "周杰伦"), 16));

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