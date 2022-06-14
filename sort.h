#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "DataGenerator.h"
#include "comparison_mode.h"
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <time.h>
using namespace std;

void SelectionSort_comp(int* array, int size);

void InsertionSort_comp(int* array, int size);

void FlashSort_comp(int* array, int size);

void CountingSort_comp(int* array, int size);

void ShakerSort_comp(int* array, int size);

void RadixSort_comp(int* array, int size);

void bubbleSort_comp(int arr[], int n);

void quickSort1_comp(int* arr, int l, int r, int& comp);
void quickSort_comp(int* arr, int n);

int shellSort_comp(int* arr, int n);

void heapify_comp(int* a, int n, int i, int& comp);
void heapSort_comp(int* a, int n);


