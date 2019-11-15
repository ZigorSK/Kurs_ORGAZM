#include "Model.h"

Model::Model()
{
	Controller obg;

	//init type of comand
	type_of_comand[0] = obg.probability(0.9);
	type_of_comand[1] = obg.probability(0.7);
	type_of_comand[2] = obg.probability(0.5);
	//init type of operand
	type_of_operand[0] = obg.probability(0.9);
	type_of_operand[1] = obg.probability(0.8);
	type_of_operand[2] = obg.probability(0.6);
}

int Model::find_middle_time_pipeline()
{
	Controller obg;
	float middle_time = 0;
	
	for(int i = 0; i < 3;i++)
		middle_time += obg.find_pipeline_comand_time(type_of_comand[i], type_of_operand[i], i);

	middle_time = middle_time / 3;

	return middle_time;
}
