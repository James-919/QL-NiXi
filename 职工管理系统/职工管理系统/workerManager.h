#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>//�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�������ռ�
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"


class WorekerManager
{
public:

	WorekerManager();//���캯��

	void show_Menu();//չʾ�˵�

	void ExitSystem();//�˳�ϵͳ

	int m_EmpNum;//��¼ְ������

	Worker ** m_EmpArray;//ְ������ָ��

	void Add_Emp();//���ְ��

	void save();//�����ļ�

	bool m_FileIsEmpty;//�ж��ļ��Ƿ�Ϊ��

	int get_EmpNum();//ͳ���ļ�������

	void init_Emp();//��ʼ��Ա��

	void Show_Emp();//��ʾְ��

	void Del_Emp();//ɾ��ְ��

	int IsExist(int id);//�ж�ְ���Ƿ����

	void Mod_Emp();//�޸�ְ��

	void Find_Emp();//����ְ��

	void Sort_Emp();//����ְ���������

	void Clean_File();//����ļ�





	~WorekerManager();//��������
};