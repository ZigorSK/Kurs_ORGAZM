/*



*/
#include<iostream>

#include"Model.h"

int main()
{
	Model obg;
	setlocale(LC_ALL, "Rus");
	std::cout << "������� ����� ���������� ������� ��������: " << obg.find_middle_time_pipeline()<<std::endl;
	system("pause");

	return 0;
}