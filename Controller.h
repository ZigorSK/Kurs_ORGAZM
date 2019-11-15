#pragma once
#include<cstdlib>
#include<ctime>

class Controller
{
public:
	bool probability(float prob);// argument is probability of event 
	int find_pipeline_comand_time(bool type_of_comand, bool type_of_operand, int num);
};