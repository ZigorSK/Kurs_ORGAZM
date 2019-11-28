#pragma once
#include"Model.h"
#include<cstdlib>
#include<ctime>
#include<iostream>

class Controller
{
	Model *arr_of_pipeline;
	int N;
public:

	Controller();
	~Controller();

	int find_middle_time_pipeline();
	int find_pipeline_comand_time(bool type_of_comand, bool type_of_operand, int num);
};