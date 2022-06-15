#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "DataGenerator.h"
#include "comparison_mode.h"
#include "sort.h"
using namespace std;

int output_order(string order);


void cout_comp(int al, int size, int * a);

void cout_time(int al, int size, int * a);

int input_order(string order);

void cout_input(int order,int size , string name);

int al_order(string order);

void cout_al(int order);

void AlgorithmMode(int temp_argc ,char* temp_argv[]);
