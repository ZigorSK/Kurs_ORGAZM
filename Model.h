#pragma once

class Model
{
	bool type_of_comand[3];// true - the first type(1 tact), false - the second tipe of comand((4,8,16) tact). Probability, that comand of the second type - (0.9;0.7;0.5)
	bool type_of_operand[3];// true - register, false - region of memory
public:
	Model();

	bool *get_type_of_comand() { return type_of_comand; };
	bool *get_type_of_operand() { return type_of_operand; };

	bool probability(float dat);
};