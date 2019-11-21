#include "Controller.h"


int Controller::find_pipeline_comand_time(bool type_of_comand, bool type_of_operand, int num)
{
	int count = 0;

	count++;//чтение и дешифрация
	count++;// выбор первого операнда(регистр)

	//обращение ко 2 операнду
	if (type_of_operand == true)
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
		count++;//регистр
	}

	//Выполнение команды
	if (type_of_comand == true)
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
		count++;//регистр
	}


	//Запись данных(Во 2-й операнд)
	if (type_of_operand == true)
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
		count++;//регистр
	}
	return count;
}

int Controller::find_middle_time_pipeline()
{
	float middle_time = 0;
	
	for (int i = 0; i < 3; i++)
		middle_time +=( find_pipeline_comand_time(*(obg1.get_type_of_comand() + i), *(obg1.get_type_of_operand() + i), i));

	middle_time = middle_time / 3;

	return middle_time;
	
}
