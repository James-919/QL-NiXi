#include<iostream>
using namespace std;
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

//ְ������ϵͳ

int main()
{
	WorekerManager wm;//ʵ���������߶���

	int chioce = 0;//�洢�û�ѡ��

	while (true)
	{
		wm.show_Menu();//����չʾ�˵�����
		cout << "����������ѡ��" << endl;
		cin >> chioce;//�����û���ѡ��

		switch (chioce)
		{
		case 0://�˳�ϵͳ
			wm.ExitSystem();
			    break;
		case 1://����ְ��
			wm.Add_Emp();
				break; 
		case 2://��ʾְ��
			wm.Show_Emp();
				break;
		case 3://ɾ��ְ��
			wm.Del_Emp();
				break;
		case 4://�޸�ְ��
			wm.Mod_Emp();
				break;
		case 5://����ְ��
			wm.Find_Emp();
				break;
		case 6://����ְ��
			wm.Sort_Emp();
			    break;
		case 7://����ĵ�
			wm.Clean_File();
			    break;
		default:
			system("cls");//����
			    break;

		}
	}

	system("pause");
	return 0;
}