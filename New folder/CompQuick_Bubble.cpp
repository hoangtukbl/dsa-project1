#include <iostream>
#include <fstream>
using namespace std;

void swap(int& x, int& y){
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
void quickSort1(int* arr, int l, int r, int& comp) {

	int p = arr[(l + r) / 2];//lay pivot la so o giua

	int i = l, j = r;

	while (++comp && i < j) {//i<j: chua duyet het mang
		while (++comp && arr[i] < p)
		{
			i++;
		}
		while (++comp && arr[j] > p) {
			j--;
		}
		if (++comp && i <= j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if (i < r) {
		quickSort1(arr, i, r, comp);
	}
	if (l < j) {
		quickSort1(arr, l, j, comp);
	}
}
void quickSort(int* arr, int n) {
	int comp = 0;
	quickSort1(arr, 0, n - 1, comp);
	printArray(arr, n);
	cout << "\nComparision: " << comp;
	cout << "\nFinish!!";
}

////////////////////////////////////////////////////////////

//BUBBLE SORT (Nguon: https://nguyenvanhieu.vn)
void bubbleSort1(int* arr, int n, int& comp)
{
	int i, j;
	bool haveSwap = false;
	for (i = 0; i < n - 1; i++) {
		++comp; //i<n-1
		haveSwap = false;
		for (j = 0; j < n - i - 1; j++) {
			++comp; //j<n-i-1
			if (++comp && arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				haveSwap = true; 
			}
		}
		if (++comp && haveSwap == false) {
			break;
		}
	}
}
void bubbleSort(int* arr, int n) {
	int comp = 0;
	bubbleSort1(arr, n, comp);
	printArray(arr, n);
	cout << "\nComparision: " << comp;
	cout << "\nFinish!!";
}



