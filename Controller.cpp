#include "Controller.h"


int Controller::find_pipeline_comand_time(int num)
{
		int count = 0;
		int t1 = 0, t2 = 0, t3 = 0;
		count++;//чтение и дешифрация(Одновременно)

		count++;// выбор первого операнда(регистр) (Одновременно)

		//обращение ко 2 операнду(Одновременно, т.е. выбираем мах из 3-х
		//middle_time[j] += (find_pipeline_comand_time(*(arr_of_pipeline[i].get_type_of_comand() + j), *(arr_of_pipeline[i].get_type_of_operand() + j), j));
		//Для первой операции
		if (!(*(arr_of_pipeline[num].get_type_of_operand())))
		{
			t1 = 2;
		}
		else
		{
			t1 = 1;//регистр
		}

		//Для второй операции
		if (!(*(arr_of_pipeline[num].get_type_of_operand()) + 1))
		{
			t2 = 5;
		}
		else
		{
			t2 = 1;//регистр
		}

		//Для 3-й операции 
		if (!(*(arr_of_pipeline[num].get_type_of_operand()) + 2))
		{
			t3 = 10;
		}
		else
		{
			t3 = 1;//регистр
		}

		count += maxim(t1, t2, t3);//Т.к. одновременно, то находим максимум из 3-х

		//Выполнение команды ( Не одновременно) поэтмоу выполняется за суммарное количество тактов
		if (!(*(arr_of_pipeline[num].get_type_of_comand() + 0)))//команда второго типа, выполнряется за (4, 8, 16) тактов
		{
			count +=4;
		}
		else
		{
			count++;//Команда 1-го типа, выполняется за 1 такт
		}

		if (!(*(arr_of_pipeline[num].get_type_of_comand() + 1)))//команда второго типа, выполнряется за (4, 8, 16) тактов
		{
			count += 8;
		}
		else
		{
			count++;//Команда 1-го типа, выполняется за 1 такт
		}

		if (!(*(arr_of_pipeline[num].get_type_of_comand() + 2)))//команда второго типа, выполнряется за (4, 8, 16) тактов
		{
			count += 16;
		}
		else
		{
			count++;//Команда 1-го типа, выполняется за 1 такт
		}

		//Запись данных по адресу второго операнда (одновременно, поэтому рассматривам максимальное)
		if (!(*(arr_of_pipeline[num].get_type_of_operand())))
		{
			t1 = 2;
		}
		else
		{
			t1 = 1;//регистр
		}

		//Для второй операции
		if (!(*(arr_of_pipeline[num].get_type_of_operand()) + 1))
		{
			t2 = 5;
		}
		else
		{
			t2 = 1;//регистр
		}

		//Для 3-й операции 
		if (!(*(arr_of_pipeline[num].get_type_of_operand()) + 2))
		{
			t3 = 10;
		}
		else
		{
			t3 = 1;//регистр
		}

		count += maxim(t1, t2, t3);//Т.к. одновременно, то находим максимум из 3-х

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
		std::cout << "Введите количество циклов работы конвеера, для получения более точной оценки среднего времени работы: " << std::endl;
		std::cin >> n;
		if ((n < 1) || ( n >= 1100))
			throw n;
		N = n;
	}
	catch(int n)
	{
		std::cout << "Введённое значение меньше 1 или больше 1100 = " << n <<"Количество прогонов конвеера будет равно 1, если введено меньше 1 или 1100, если больше 1100." <<std::endl;
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
