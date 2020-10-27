#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>

class Person
{
public:
	string m_Name;//选手姓名
	int m_Score;//选手得分
	Person(string name, int score)
	{
		m_Name = name;
		m_Score = score;
	}

};

void createPerson(vector<Person>&v)
{
	string nameSeed = "ABCDE";//string容器赋值操作
	for (int i = 0; i < 5; i++)
	{
		string name="选手";//string容器赋值操作
		name += nameSeed[i];//重载+=:字符串拼接  重载[]对string中单个字符存取

		int score = 0;

		Person p(name, score);

		//将创建的person对象放入容器中
		v.push_back(p);
	}

}

//打分
void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//将评委的打分放入到deque容器中
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//60 ~ 100
			d.push_back(score);
		}

		/*cout << "选手： " << it->m_Name << "打分： " << endl;
		for (deque<int>::iterator dit = 
		d.begin(); dit != d.end(); it++)
		{
			cout << *dit << " ";
		}
		cout << endl;*/

		//先排序
		sort(d.begin(), d.end());

		//去除最高分和最低分
		d.pop_back();
		d.pop_front();

		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += * dit;//累加评委分数
		}

		int avg = sum / d.size();

		//将平均分赋给选手
		it->m_Score = avg;

	}
}

void showScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{

		cout << "姓名： " << it->m_Name << "    平均分： " << it->m_Score << endl;
	}

}

int main()
{

	//随机数种子
	srand((unsigned int)time(NULL));

	//1、创建五名选手
	vector<Person> v;
	createPerson(v);

	/*for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << "  分数： " << (*it).m_Score << endl;
	}*/

	//2、给五名选手打分
	setScore(v);

	//3、显示最后得分
	showScore(v);

	system("pause");
	return 0;
}