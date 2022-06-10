#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "DataGenerator.h"
using namespace std;

int output_order(string order);

void cout_output(int order);

int input_order(string order);

void cout_input(int order);

int al_order(string order);

void cout_al(int order);

void AlgorithmMode(int temp_argc ,char* temp_argv[]);
