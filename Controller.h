#pragma once
#include"Model.h"
#include<cstdlib>
#include<ctime>

class Controller
{
	Model obg1;
public:

	int find_middle_time_pipeline();
	int find_pipeline_comand_time(bool type_of_comand, bool type_of_operand, int num);
};