#pragma once
#include "algorithm_mode.h"
#include "DataGenerator.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void make_input_file(int order ,int size,string name);

void cout_2al(int order1 , int order2);
void ComparisonMode(int temp_argc , char* temp_argv[]);
