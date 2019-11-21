/*



*/
#include<iostream>
#include<windows.h>
#include"Controller.h"

int main()
{
	const int N = 20;
	float count = 0;
	Controller *obg;
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		obg = new Controller;
		std::cout << "Среднее время выполнения команды конвеера: " << obg[i].find_middle_time_pipeline() << std::endl;
		//system("pause");
		//Sleep(1000);
		delete[] obg;
	}
	std::cout << count / 20;
	system("pause");
	return 0;
}