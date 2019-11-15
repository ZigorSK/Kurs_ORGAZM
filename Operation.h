#pragma once

class Operation
{
    int type_of_comand;// 0 - the fist type of comand, 1 - the second type of comand
	int type_of_cmd2;// 0 - register, 1 - inderect address

public:
	Operation(int tcom = 0, int tcmd = 0) : type_of_comand(tcom), type_of_cmd2(tcmd) {};

	int ger_type_of_comand() { return type_of_comand; };
	void set_type_of_comand(int tcom) { type_of_comand = tcom; };

	int ger_type_of_cmd2() { return type_of_cmd2; };
	void set_type_of_cmd2(int tcom) { type_of_cmd2 = tcom; };
};