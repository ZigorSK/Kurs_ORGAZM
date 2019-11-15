
#include "Controller.h"

bool Controller::probability(float prob)
{
	bool arr[10];
	int choice = 0;
	srand(time(NULL));
	for (int i = 0; i < 9; i++)
	{
		if (prob > 0)
		{
			*(arr + i) = true;
		}
		else
		{
			*(arr + i) = false;
		}
		prob -= 0.1;
	}

	choice = round(rand() % 10);
	return *(arr + choice);
}

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
