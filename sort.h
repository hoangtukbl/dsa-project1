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

void shellSort_comp(int* arr, int n);

void heapify_comp(int* a, int n, int i, int& comp);
void heapSort_comp(int* a, int n);

void mergeArray_comp(int* a, int const begin, int const mid, int const end, int& comp);
void mergeSort_comp(int* a, int const begin, int const end, int& comp);
void mergeSort_main_comp(int* arr , int size);

void SelectionSort_time(int* array, int size);

void InsertionSort_time(int* array, int size);

void RadixSort_time(int* array, int size);

void ShakerSort_time(int* array, int size);

void CountingSort_time(int* array, int size);

void FlashSort_time(int* array, int size);

void shellSort_time(int* arr, int n);

void heapify_time(int* a, int n, int i);
void heapSort_time(int* a, int n);

void mergeArray_time(int* a, int const begin, int const mid, int const end);
void mergeSort_time(int* a, int const begin, int const end);
void mergeSort_main_time(int* arr , int size);

void quickSort1_time(int* arr, int l, int r);
void quickSort_time(int* arr, int n);

void bubbleSort_time(int arr[], int n);

