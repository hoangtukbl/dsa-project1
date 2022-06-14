#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void printArray(int* a, int n) {
	ofstream file;
	file.open("output.txt", ofstream::out);
	file << "\nSo phan tu: " << n << endl;
	for (int i = 0; i < n; i++) {
		file << a[i] << " ";
	}
	file.close();
}

//QUICK SORT (nguon: Banh Minh Phuong)
void quickSort1(int* arr, int l, int r) {

	int p = arr[(l + r) / 2];//lay pivot la so o giua

	int i = l, j = r;

	while (i < j) {//i<j: chua duyet het mang
		while (arr[i] < p)
		{
			i++;
		}
		while (arr[j] > p) {
			j--;
		}
		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if (i < r) {
		quickSort1(arr, i, r);
	}
	if (l < j) {
		quickSort1(arr, l, j);
	}
}
void quickSort(int* arr, int n) {
	clock_t start, end;
	start = clock();
	quickSort1(arr, 0, n - 1);
	end = clock();
	double time = (end - start) / (CLOCKS_PER_SEC / 1000);
	printArray(arr, n);
	cout << "\nRunning time: " << time << "ms";
	cout << "\nFinish!!";
}

////////////////////////////////////////////////////////////

//BUBBLE SORT (Nguon: https://nguyenvanhieu.vn)
void bubbleSort1(int* arr, int n)
{
	int i, j;
	bool haveSwap = false;
	for (i = 0; i < n - 1; i++) {
		haveSwap = false;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				haveSwap = true;
			}
		}
		if (haveSwap == false) {
			break;
		}
	}
}
void bubbleSort(int* arr, int n) {
	clock_t start, end;
	start = clock();
	bubbleSort1(arr, n);
	end = clock();
	double time = (end - start) / (CLOCKS_PER_SEC / 1000);
	printArray(arr, n);
	cout << "\nRunning time: " << time << "ms";
	cout << "\nFinish!!";
}



