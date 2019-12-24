#include "Controller.h"


int Controller::find_pipeline_comand_time(int num)
{
		int count = 0;
		int t1 = 0, t2 = 0, t3 = 0;
		count++;//������ � ����������(������������)

		count++;// ����� ������� ��������(�������) (������������)

		//��������� �� 2 ��������(������������, �.�. �������� ��� �� 3-�
		//middle_time[j] += (find_pipeline_comand_time(*(arr_of_pipeline[i].get_type_of_comand() + j), *(arr_of_pipeline[i].get_type_of_operand() + j), j));
		//��� ������ ��������
		if (!(*(arr_of_pipeline[num].get_type_of_operand())))
		{
			t1 = 2;
		}
		else
		{
			t1 = 1;//�������
		}

		//��� ������ ��������
		if (!(*(arr_of_pipeline[num].get_type_of_operand()) + 1))
		{
			t2 = 5;
		}
		else
		{
			t2 = 1;//�������
		}

		//��� 3-� �������� 
		if (!(*(arr_of_pipeline[num].get_type_of_operand()) + 2))
		{
			t3 = 10;
		}
		else
		{
			t3 = 1;//�������
		}

		count += maxim(t1, t2, t3);//�.�. ������������, �� ������� �������� �� 3-�

		//���������� ������� ( �� ������������) ������� ����������� �� ��������� ���������� ������
		if (!(*(arr_of_pipeline[num].get_type_of_comand() + 0)))//������� ������� ����, ������������ �� (4, 8, 16) ������
		{
			count +=4;
		}
		else
		{
			count++;//������� 1-�� ����, ����������� �� 1 ����
		}

		if (!(*(arr_of_pipeline[num].get_type_of_comand() + 1)))//������� ������� ����, ������������ �� (4, 8, 16) ������
		{
			count += 8;
		}
		else
		{
			count++;//������� 1-�� ����, ����������� �� 1 ����
		}

		if (!(*(arr_of_pipeline[num].get_type_of_comand() + 2)))//������� ������� ����, ������������ �� (4, 8, 16) ������
		{
			count += 16;
		}
		else
		{
			count++;//������� 1-�� ����, ����������� �� 1 ����
		}

		//������ ������ �� ������ ������� �������� (������������, ������� ������������ ������������)
		if (!(*(arr_of_pipeline[num].get_type_of_operand())))
		{
			t1 = 2;
		}
		else
		{
			t1 = 1;//�������
		}

		//��� ������ ��������
		if (!(*(arr_of_pipeline[num].get_type_of_operand()) + 1))
		{
			t2 = 5;
		}
		else
		{
			t2 = 1;//�������
		}

		//��� 3-� �������� 
		if (!(*(arr_of_pipeline[num].get_type_of_operand()) + 2))
		{
			t3 = 10;
		}
		else
		{
			t3 = 1;//�������
		}

		count += maxim(t1, t2, t3);//�.�. ������������, �� ������� �������� �� 3-�

	return count;
}

int Controller::maxim(int t1, int t2, int t3)
{
	if (t1 > t2)
	{
		if (t1 > t3)
		{
			return t1;
		}
		else//t3>t1
		{
			return t3;
		}
	}
	else//t2>t1
	{
		if (t2 > t3)
		{
			return t2;
		}
		else
		{
			return t3;
		}
	}
}

Controller::Controller()
{
	int n = 1;

	try
	{
		std::cout << "������� ���������� ������ ������ ��������, ��� ��������� ����� ������ ������ �������� ������� ������: " << std::endl;
		std::cin >> n;
		if ((n < 1) || ( n >= 1100))
			throw n;
		N = n;
	}
	catch(int n)
	{
		std::cout << "�������� �������� ������ 1 ��� ������ 1100 = " << n <<"���������� �������� �������� ����� ����� 1, ���� ������� ������ 1 ��� 1100, ���� ������ 1100." <<std::endl;
		system("pause");
		system("cls");
		if (n < 1)
		{
			N = 1;
		}
		else
		{
			N = 1100;
		}
	}
	srand(time(NULL));

	arr_of_pipeline = new Model[N];

}

Controller::~Controller()
{
	delete[] arr_of_pipeline;
}
