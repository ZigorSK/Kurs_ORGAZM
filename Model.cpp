#include "Model.h"
#include <ctime>
#include <stdlib.h>
Model::Model()
{
	//init type of comand
	type_of_comand[0] = probability(0.9);
	type_of_comand[1] = probability(0.7);
	type_of_comand[2] = probability(0.5);
	//init type of operand
	type_of_operand[0] = probability(0.9);
	type_of_operand[1] = probability(0.8);
	type_of_operand[2] = probability(0.6);
}

bool Model::probability(float prob)
{
	try
	{
		if ((prob < 0) || (prob > 1))
			throw prob;
		bool arr[10];
		int choice = 0;

		for (int i = 0; i < 10; i++)
		{
			if (prob > 0)
			{
				*(arr + i) = true;
			}
			else
			{
				*(arr + i) = false;
			}
			prob = prob - 0.1;
		}

		choice = rand() % 10;

		return *(arr + choice);
	}
	catch(float p)
	{
		std::cout << " Переданая в метод вероятность меньше 0 или больше 1, будет возвращено значание false!" << std::endl;
		system("pause");
		system("cls");
		return false;
	}
}
