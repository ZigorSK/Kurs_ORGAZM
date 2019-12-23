#pragma once
#include"Model.h"
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

class Controller
{
	Model *arr_of_pipeline;
	int N;
public:

	Controller();
	~Controller();

	int get_num() { return N; };

	int find_pipeline_comand_time(int num);

	int maxim(int t1, int t2, int t3);
};
