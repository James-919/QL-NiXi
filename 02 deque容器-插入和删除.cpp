#include<iostream>
using namespace std;
#include<deque>

//�����ɾ��

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)//const_iterator:ֻ���ĵ�����
	{
		cout << *it << "  ";
	}
	cout << endl;
}

//���˲���
void test01()
{
	deque<int> d1;

	//β��
	d1.push_back(10);
	d1.push_back(20);
	
	//ͷ��
	d1.push_front(100);
	d1.push_front(200);

	printDeque(d1);

	//βɾ
	d1.pop_back();
	printDeque(d1);

	//ͷɾ
	d1.pop_front();
	printDeque(d1);

}

//ָ��λ��

void test02()
{
	deque<int> d2;
	d2.push_back(10);
	d2.push_back(20);
	d2.push_front(100);
	d2.push_front(200);
	printDeque(d2);

	//insert����
	d2.insert(d2.begin(), 1000);
	printDeque(d2);

	d2.insert(d2.begin(),2, 10000);
	printDeque(d2);

	deque<int> d3;
	d3.push_back(1);
	d3.push_back(2);
	d3.push_back(3);

	d2.insert(d2.begin(), d3.begin(), d3.end());
	printDeque(d2);

}

//ɾ��

void test03()
{
	deque<int> d2;
	d2.push_back(10);
	d2.push_back(20);
	d2.push_front(100);
	d2.push_front(200);
	printDeque(d2);

	d2.erase(d2.begin());
	printDeque(d2);

	//d2.erase(d2.begin(), d2.end());
	//printDeque(d2);

	d2.clear();
	printDeque(d2);

}


int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}