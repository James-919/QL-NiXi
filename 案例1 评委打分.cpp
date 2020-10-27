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
	string m_Name;//ѡ������
	int m_Score;//ѡ�ֵ÷�
	Person(string name, int score)
	{
		m_Name = name;
		m_Score = score;
	}

};

void createPerson(vector<Person>&v)
{
	string nameSeed = "ABCDE";//string������ֵ����
	for (int i = 0; i < 5; i++)
	{
		string name="ѡ��";//string������ֵ����
		name += nameSeed[i];//����+=:�ַ���ƴ��  ����[]��string�е����ַ���ȡ

		int score = 0;

		Person p(name, score);

		//��������person�������������
		v.push_back(p);
	}

}

//���
void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//����ί�Ĵ�ַ��뵽deque������
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//60 ~ 100
			d.push_back(score);
		}

		/*cout << "ѡ�֣� " << it->m_Name << "��֣� " << endl;
		for (deque<int>::iterator dit = 
		d.begin(); dit != d.end(); it++)
		{
			cout << *dit << " ";
		}
		cout << endl;*/

		//������
		sort(d.begin(), d.end());

		//ȥ����߷ֺ���ͷ�
		d.pop_back();
		d.pop_front();

		//ȡƽ����
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += * dit;//�ۼ���ί����
		}

		int avg = sum / d.size();

		//��ƽ���ָ���ѡ��
		it->m_Score = avg;

	}
}

void showScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{

		cout << "������ " << it->m_Name << "    ƽ���֣� " << it->m_Score << endl;
	}

}

int main()
{

	//���������
	srand((unsigned int)time(NULL));

	//1����������ѡ��
	vector<Person> v;
	createPerson(v);

	/*for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������ " << (*it).m_Name << "  ������ " << (*it).m_Score << endl;
	}*/

	//2��������ѡ�ִ��
	setScore(v);

	//3����ʾ���÷�
	showScore(v);

	system("pause");
	return 0;
}