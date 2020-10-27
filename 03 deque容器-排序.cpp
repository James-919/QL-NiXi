#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>//标准算法头文件

//排序

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)//const_iterator:只读的迭代器
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void test01()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	cout << "排序前： " << endl;
    printDeque(d);

	//利用sort排序
	sort(d.begin(), d.end());//sort默认升序
	cout << "排序后： " << endl;
	printDeque(d);

}

int main()
{

	test01();

	system("pause");
	return 0;
}

