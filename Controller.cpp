#include "Controller.h"


int Controller::find_pipeline_comand_time(bool type_of_comand, bool type_of_operand, int num)
{
	int count = 0;

	count++;//������ � ����������

	count++;// ����� ������� ��������(�������)

	//��������� �� 2 ��������
	if (!type_of_operand)
	{
		switch (num)
		{
		case 0:
			count += 2;
			break;
		case 1:
			count += 5;
			break;
		case 2:
			count += 10;
			break;
		}
	}
	else
	{
		count++;//�������
	}

	//���������� �������
	if (!type_of_comand)//������� ������� ����, ������������ �� (4, 8, 16) ������
	{
		switch (num)
		{
		case 0:
			count += 4;
			break;
		case 1:
			count += 8;
			break;
		case 2:
			count += 16;
			break;
		}
	}
	else
	{
		count++;//������� 1-�� ����, ����������� �� 1 ����
	}


	//������ ������ �� ������ ������� ��������
	if (!type_of_operand)
	{
		switch (num)
		{
		case 0:
			count += 2;
			break;
		case 1:
			count += 5;
			break;
		case 2:
			count += 10;
			break;
		}
	}
	else
	{
		count++;//�������
	}

	return count;
}

Controller::Controller()
{
	int n = 0;

	std::cout << "������� ���������� ������ ������ ��������, ��� ��������� ����� ������ ������ �������� ������� ������: " << std::endl;
	std::cin >> n;
	N = n;
	srand(time(NULL));

	arr_of_pipeline = new Model[n];
}

Controller::~Controller()
{
	delete[] arr_of_pipeline;
}

int Controller::find_middle_time_pipeline()
{
	double middle_time[3] = {0, 0, 0};
	double count = 0;

	for (int i = 0; i< N; i++)
	{
		middle_time[0] = 0;
		middle_time[1] = 0;
		middle_time[2] = 0;

		for (int j = 0; j < 3; j++)
		{
			middle_time[j] += (find_pipeline_comand_time(*(arr_of_pipeline[i].get_type_of_comand() + j), *(arr_of_pipeline[i].get_type_of_operand() + j), j));
		}
		middle_time[1]++;
		middle_time[2] += 2;
		//

		if (middle_time[0] > middle_time[1])
		{
			if (middle_time[0] > middle_time[2])
			{
				//0
				count += middle_time[0];
			}
			else
			{
				//2
				count += middle_time[2];
			}
		}
		else
		{
			if (middle_time[1] > middle_time[2])
			{
				//1
				count += middle_time[1];
			}
			else
			{
				//2
				count += middle_time[2];
			}
		}
	}
	std::cout << count << std::endl;
	system("pause");
	return round( count/N +0.5 );
}
