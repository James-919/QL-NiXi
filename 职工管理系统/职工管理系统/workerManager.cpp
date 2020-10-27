#include"workerManager.h"

WorekerManager::WorekerManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	//2.�ļ����� ����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())//eof:�ļ�β
	{
		cout << "�ļ�Ϊ��!" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.�ļ������Ҳ�Ϊ��
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ�� " << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];//���ٿռ�
	this->init_Emp();//���ļ��е����ݴ浽������

	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ����ţ� " << this->m_EmpArray[i]->m_Id << " "
			<< "ְ�������� " << this->m_EmpArray[i]->m_Name << " "
			<< "ְ�����ű�ţ� " << this->m_EmpArray[i]->m_DeptId << endl;


	}*/


}

void WorekerManager::show_Menu()//չʾ�˵�
{
	cout << "************************************************" << endl;
	cout << "************** ��ӭʹ��ְ������ϵͳ! ***********" << endl;
	cout << "***************** 0.�˳�������� ***************" << endl;
	cout << "***************** 1.����ְ����Ϣ ***************" << endl;
	cout << "***************** 2.��ʾְ����Ϣ ***************" << endl;
	cout << "***************** 3.ɾ����ְְ�� ***************" << endl;
	cout << "***************** 4.�޸�ְ����Ϣ ***************" << endl;
	cout << "***************** 5.����ְ����Ϣ ***************" << endl;
	cout << "***************** 6.���ձ������ ***************" << endl;
	cout << "***************** 7.��������ĵ� ***************" << endl;
	cout << "************************************************" << endl;
	cout << endl;


}

void WorekerManager::ExitSystem()//�˳�ϵͳ
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����

}

void WorekerManager::Add_Emp()
{
	cout << "��������ӵ�ְ���������� " << endl;

	int addNum = 0;//�����û�����������

	cin >> addNum;

	if (addNum > 0)
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;//�¿ռ��С=ԭ����¼����+��������

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ���ռ�����ݿ������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];

			}
		}

		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��

			cout << "������� " << i + 1 << " ����ְ�����" << endl;
			cin >> id;
			cout << "������� " << i + 1 << " ����ְ������" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ " <<endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case1:
				worker = new Employee(id, name, 1);
				break;
			case2:
				worker = new Manager(id, name, 2);
				break;
			case3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			//��������ְ��ָ�뱣�浽������
			newSpace [this->m_EmpNum + i] = worker;

		}

		//�ͷ�ԭ�пռ�
		delete[]this->m_EmpArray;

		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//����ְ����Ϊ�ձ�־
		this->m_FileIsEmpty = false;


		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ��" << endl;

		//�������ݵ��ļ���
		this->save();

	}
	else
	{
		cout << "������������" << endl;
	}

	//��������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");


}

void WorekerManager::save()//�����ļ�
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//����ķ�ʽ���ļ�����д�ļ�

	//��ÿ���˵�����д���ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{

		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}


	//�ر��ļ�
	ofs.close();

}

int WorekerManager::get_EmpNum()//ͳ���ļ�������
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs>>id && ifs>>name && ifs>>dId)
	{
		//ͳ����������
		num++;
	}

	return num;

}

void WorekerManager::init_Emp()//��ʼ��Ա��
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)//��ְͨ��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//����
		{
			worker = new Manager(id, name, dId);
		}
		else//�ϰ�
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}

	ifs.close();
}

void WorekerManager::Show_Emp()//��ʾְ��
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;

	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();

		}
	}

	system("pause");
	system("cls");
}

void WorekerManager::Del_Emp()//ɾ��ְ��
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "��������Ҫɾ��ְ����ţ� " << endl;
		int id=0;
		cin >> id;

		int index=this->IsExist(id);

		if (index != -1)//˵��ְ�����ڲ���Ҫɾ����indexλ���ϵ�ְ��
		{
			for (int i = index;i<this->m_EmpNum-1;i++)
			{
				//����ǰ��
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//���������м�¼��Ա�ĸ���
			//����ͬ�����ļ���
			this->save();

			cout << "ɾ���ɹ���" << endl;

		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ����" << endl;
		}
	}

	//������� ����
	system("pause");
	system("cls");


}

int WorekerManager::IsExist(int id)//�ж�ְ���Ƿ����
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//�ҵ�ְ��
			index = i;

			break;

		}

	}
	return index;
}

void WorekerManager::Mod_Emp()//�޸�ְ��
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸ĵ�ְ�����" << endl;
		int id = 0;
		cin >> id;
		int ret=this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽��" << id << "��ְ�����������µ�ְ���ţ� " << endl;
			cin >> newId;

			cout << "�������µ������� " << endl;
			cin >> newName;

			cout << "�������µĸ�λ�� " << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}

			//��������
			this->m_EmpArray[ret] = worker;

			cout << "�޸ĳɹ���" << endl;

			//���浽�ļ���
			this->save();


		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}



	}

	system("pause");
	system("cls");



}

void WorekerManager::Find_Emp()//����ְ��
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų��� " << endl;
		cout << "2����ְ���������� " << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//��ְ����Ų���
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;

			int ret=IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else if(select==2)
		{
			//��ְ����������
			string name;
			cout << "���������ְ��������" << endl;
			cin >> name;

			bool flag = false;//Ĭ��Ϊ�ҵ�ְ��

			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ�� " << this->m_EmpArray[i]->m_Id << "��ְ����Ϣ���£�" << endl;

					flag = true;

					this->m_EmpArray[i]->showInfo();

				}

			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}

		}
		else
		{
			cout << "����ѡ���������������룡" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorekerManager::Sort_Emp()//����ְ���������
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1������" << endl;
		cout << "2������" << endl;

		int select=0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int MinOrMax = i;//������Сֵ�����ֵ���±�
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (this->m_EmpArray[MinOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
				else
				{
					if (this->m_EmpArray[MinOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}

				}

			}

			if (i != MinOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
				this->m_EmpArray[MinOrMax] = temp;

			}
		}
	}

	cout << "����ɹ����������Ϊ�� " << endl;
	this->save();//����������浽�ļ���
	this->Show_Emp();//չʾ����ְ��

}

void WorekerManager::Clean_File()//����ļ�
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//ɾ�����ٴ���
		ofs.close();

		if (this->m_EmpArray != NULL)
		{

			//ɾ������ÿ��ְ������
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}

			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;

		}

		cout << "��ճɹ���" << endl;
		
	}

	system("pause");
	system("cls");

}


WorekerManager::~WorekerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}