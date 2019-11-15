#pragma once
#include"Controller.h"

class Model
{
	bool type_of_comand[3];// false - the thirst tipe(1 tact), true - the second tipe of comand((4,8,16) tact). Probability, that comand the second tipe - (0.9;0.7;0.5)
	bool type_of_operand[3];// true - register, false - region of memory
public:
	Model();

	int find_middle_time_pipeline();

	
};