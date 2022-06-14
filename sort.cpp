#include "sort.h"

void printArray(int* a, int n) {
	ofstream file;
	file.open("output.txt", ofstream::out);
	file << "\nSo phan tu: " << n << endl;
	for (int i = 0; i < n; i++) {
		file << a[i] << " ";
	}
	file.close();
}


//đếm comparison
void SelectionSort_comp(int* array, int size)
{
	long long countCompare = 0;
	int minIndex, minValue, i = 0, j;
	
	while (++countCompare && i < size - 1)
	{
		minIndex = i;
		minValue = array[i];
		j = i + 1;
		while (++countCompare && j < size)
		{
			if (++countCompare && array[j] < minValue) 
			{
				minIndex = j;
				minValue = array[j];
			}
			++j;
		}
		array[minIndex] = array[i];
		array[i] = minValue;
		++i;
	}
	
	printArray(array, size);
	cout << "Comparisions: " << countCompare << endl;
}

void InsertionSort_comp(int* array, int size)
{
	long long countCompare = 0;
	int temp = array[0], v, i = 1, j;
	
	array[0] = -100;
	while (++countCompare && i < size)
	{
		v = array[i];
		j = i - 1;
		while(++countCompare && array[j] > v)
		{ 
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = v;
		++i;
	} 
	j = 1;
	while(++countCompare && array[j] < temp)
	{  
		array[j - 1] = array[j];
		++j;
	} 
	array[j - 1] = temp;
	
	printArray(array, size);
	cout << "Comparisions: " << countCompare << endl;
}

void RadixSort_comp(int* array, int size)
{
	long long countCompare = 0;
	int i = 1, max = array[0], exp = 1, countArray[10];
	int* temp = new int[size];
	
	while (++countCompare && i < size)
	{
		if(++countCompare && array[i] > max)
			max = array[i];
		++i;
	}
	while(++countCompare && max / exp > 0)
    {
    	i = 0;
    	while(++countCompare && i < 10)
    	{
    		countArray[i] = 0;
    		++i;
		}
		i = 0;
		while(++countCompare && i < size)
    	{
    		++countArray[(array[i] / exp) % 10];
    		++i;
		}
		i = 1;
		while(++countCompare && i < 10)
    	{
    		countArray[i] += countArray[i - 1];
    		++i;
		}
		i = size - 1;
		while(++countCompare && i >= 0)
    	{
    		temp[countArray[(array[i] / exp) % 10] - 1] = array[i];
        	--countArray[(array[i] / exp) % 10];
    		--i;
		}
		i = 0;
		while(++countCompare && i < size)
		{
			array[i] = temp[i];
			++i;	
		} 
    	exp *= 10;
	}
	delete[] temp;
	
	printArray(array, size);
	cout << "Comparisions: " << countCompare << endl;
}

void ShakerSort_comp(int* array, int size)
{
	long long countCompare = 0;
	int left = 0, right = size - 1, k = 0, i = 0, j;
	
	while (++countCompare && i <= right)
	{
		int swapped = 0;
		j = left;
		while (++countCompare && j < right)
		{
			if (++countCompare && array[j] > array[j + 1])
			{
				swapped = 1;
				swap(array[j], array[j + 1]);
				k = j;
			}
			++j;
		}
		if (++countCompare && !swapped)
			return;
		right = k;
		swapped = 0;
		j = right;
		while (++countCompare && j > left)
		{
			if (++countCompare && array[j] < array[j - 1])
			{
				swapped = 1;
				swap(array[j], array[j - 1]);
				k = j;
			}
			--j;
		}
		if (++countCompare && !swapped)
			return;
		left = k;
		++i;
	}

	printArray(array, size);
	cout << "Comparisions: " << countCompare << endl;
}

void CountingSort_comp(int* array, int size)
{
	long long countCompare = 0;
	int i = 1, max = array[0], j;
	
	while (++countCompare && i < size)
	{
		if (++countCompare && array[i] > max)
			max = array[i];
		++i;
	}
	int *count = new int[max + 1];
	i = 0;
	while (++countCompare && i <= max)
	{
		count[i] = 0;
		++i;
	}
	i = 0;
	while (++countCompare && i < size)
	{
		++count[array[i]];
		++i;
	}
	i = 1;
	while (++countCompare && i <= max)
	{
		count[i] += count[i - 1];
		++i;
	}
	int *temp = new int[size];
	i = 0;
	while (++countCompare && i < size)
	{
		temp[count[array[i]] - 1] = array[i];
		--count[array[i]];
		++i;
	}
	i = 0;
	while (++countCompare && i < size)
	{
		array[i] = temp[i];
		++i;
	}
	delete[] count;
	delete[] temp;
	
	printArray(array, size);
	cout << "Comparisions: " << countCompare << endl;
}

void FlashSort_comp(int* array, int size)
{
	long long countCompare = 0;
	int minVal = array[0], max = 0, m = int(0.45 * size), * l = new int[m], i = 0;
	
	while(++countCompare && i < m)
	{
		l[i] = 0;
		++i;
	}
	i = 1;
	while(++countCompare && i < size)
	{
		if (++countCompare && array[i] < minVal)
			minVal = array[i];
		else if (++countCompare && array[i] > array[max])
			max = i;
		++i;
	}
	if (++countCompare && array[max] == minVal)
	{
		delete[] l;
		return;
	}
	double c1 = (double)(m - 1) / (array[max] - minVal);
	i = 0;
	while(++countCompare && i < size)
	{
		int k = int(c1 * (array[i] - minVal));
		++l[k];
		++i;
	}
	i = 1;
	while(++countCompare && i < m)
	{
		l[i] += l[i - 1];
		++i;
	}
	swap(array[max], array[0]);
	int nmove = 0, j = 0, k = m - 1, flash;
	while (++countCompare && nmove < size - 1)
	{
		while (++countCompare && j > l[k] - 1)
		{
			++j;
			k = int(c1*(array[j] - minVal));
		}
		flash = array[j];
		if (++countCompare && k < 0) break;
		while (++countCompare && j != l[k])
		{
			k = int(c1*(flash - minVal));
			--l[k];
			swap(flash, array[l[k]]);
			++nmove;
		}
	}
	delete[] l;
	
	int v, temp = array[0];
	array[0] = -100;
	i = 1;
	while (++countCompare && i < size)
	{
		v = array[i];
		j = i - 1;
		while(++countCompare && array[j] > v)
		{ 
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = v;
		++i;
	} 
	j = 1;
	while(++countCompare && array[j] < temp)
	{  
		array[j - 1] = array[j];
		++j;
	} 
	array[j - 1] = temp;
	
	printArray(array, size);
	cout << "Comparisions: " << countCompare << endl;
}

void bubbleSort_comp(int arr[], int n)
{
	int comp = 0;
	int i, j;
	for (i = 0;++comp && i < n - 1; i++)

		// Last i elements are already 
		// in place
		for (j = 0;++comp && j < n - i - 1; j++)
			if (++comp && arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
	printArray(arr, n);
	cout << "Comparision: " << comp<<endl;
	// cout << "\nFinish!!";
}

void quickSort1_comp(int* arr, int l, int r, int& comp) {

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
		quickSort1_comp(arr, i, r, comp);
	}
	if (l < j) {
		quickSort1_comp(arr, l, j, comp);
	}
}
void quickSort_comp(int* arr, int n) {
	int comp = 0;
	quickSort1_comp(arr, 0, n - 1, comp);
	printArray(arr, n);
	cout << "Comparision: " << comp <<endl;
}

int shellSort_comp(int* arr, int n)
{
	long long comp = 0;
	// Start with a big gap, then reduce the gap
	for (int gap = n / 2; ++comp && gap > 0; gap /= 2)
	{
		for (int i = gap; ++comp && i < n; i += 1)
		{
			int temp = arr[i];

			int j;
			for (j = i; (++comp && j >= gap) && (++comp && arr[j - gap] > temp); j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
	printArray(arr, n);
	cout << "Comparision: " << comp<<endl;
	return 0;

}

//THIS CODE IS THE IMPLEMENTATION OF HEAP SORT
// To heapify a subtree rooted with node i
// which is an index in a.
// n is size of heap
void heapify_comp(int* a, int n, int i, int& comp)
{

	// Initialize largest as root
	int largest = i;

	// left = 2*i + 1
	int l = 2 * i + 1;

	// right = 2*i + 2
	int r = 2 * i + 2;

	// If left child is larger than root
	if ((++comp && l < n) && (++comp && a[l] > a[largest]))
		largest = l;

	// If right child is larger than largest
	// so far
	if ((++comp && r < n) && (++comp && a[r] > a[largest]))
		largest = r;

	// If largest is not root
	if (++comp && largest != i) {
		swap(a[i], a[largest]);

		// Recursively heapify the affected
		// sub-tree
		heapify_comp(a, n, largest, comp);
	}
}
// Main function to do heap sort
void heapSort_comp(int* a, int n)
{
	int comp = 0;
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify_comp(a, n, i, comp);

	// One by one extract an element
	// from heap
	for (int i = n - 1; ++comp && i > 0; i--) {

		// Move current root to end
		swap(a[0], a[i]);

		// call max heapify on the reduced heap
		heapify_comp(a, i, 0, comp);
	}

	printArray(a, n);
	cout << "Comparision: " << comp<<endl;
}

void mergeArray_comp(int* a, int const begin, int const mid, int const end, int& comp)
{
	//Create count variables
	int l = mid - begin + 1, r = end - mid, m = begin;
	int il = 0, ir = 0;

	//Create subarrays
	int* Left, * Right;
	Left = new int[l];
	Right = new int[r];

	//Enter numbers to subarray
	for (int i = 0; ++comp && i < l; i++)
	{
		Left[i] = a[i + begin];
	}

	for (int j = 0; ++comp && j < r; j++)
	{
		Right[j] = a[mid + 1 + j];
	}

	//Sorting to Merge array
	while ((++comp && il < l) && (++comp && ir < r))
	{
		if (++comp && Left[il] <= Right[ir])
		{
			a[m] = Left[il];
			il++;
		}
		else
		{
			a[m] = Right[ir];
			ir++;
		}
		m++;
	}

	//Input the remaining elements if there is any
	while (++comp && il < l)
	{
		a[m] = Left[il];
		il++; m++;
	}

	while (++comp && ir < r)
	{
		a[m] = Right[ir];
		ir++; m++;
	}

}
//Main merge sort function
void mergeSort_comp(int* a, int const begin, int const end, int& comp)
{
	//Return if array is divided into the smallest element
	if (++ comp && begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort_comp(a, begin, mid, comp);
	mergeSort_comp(a, mid + 1, end, comp);

	//Merge and sort subarrays
	mergeArray_comp(a, begin, mid, end, comp);

}
void mergeSort_main_comp(int* arr , int size)
{
	int begin = 0 ;
	int end = size - 1;
	int comp = 0;
	mergeSort_comp(arr, begin, end, comp);
	printArray(arr, size);
	cout << "Comparision: " << comp<<endl;
}


//tính running time


void SelectionSort_time(int* array, int size)
{
	clock_t begin, end;
	double time;
	int minIndex, minValue;
	
	begin = clock();
	for(int i = 0; i < size - 1; ++i)
	{
		minIndex = i;
		minValue = array[i];
		for (int j = i + 1; j < size; ++j)
			if (array[j] < minValue) 
			{
				minIndex = j;
				minValue = array[j];
			}
		array[minIndex] = array[i];
		array[i] = minValue;
	}
	end = clock();
	
	time = (double)(end - begin) / (CLOCKS_PER_SEC / 1000);
	printArray(array, size);
	cout << "Running time: " << time << " ms" << endl;
}

void InsertionSort_time(int* array, int size)
{
	clock_t begin, end;
	double time;
	int temp = array[0], v, j;
	
	begin = clock();
	array[0] = -100;
	for (int i = 1; i < size; ++i)
	{
		v = array[i];
		j = i - 1;
		while(array[j] > v)
		{ 
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = v;
	} 
	j = 1;
	while(array[j] < temp)
	{  
		array[j - 1] = array[j];
		++j;
	} 
	array[j - 1] = temp;
	end = clock();
	
	time = (double)(end - begin) / (CLOCKS_PER_SEC / 1000);
	printArray(array, size);
	cout << "Running time: " << time << " ms" << endl;
}

void RadixSort_time(int* array, int size)
{
	clock_t begin, end;
	double time;
	int max = array[0], exp = 1, countArray[10];
	int* temp = new int[size];
	
	begin = clock();
	for (int i = 1; i < size; ++i)
		if(array[i] > max)
			max = array[i];
	while(max / exp > 0)
    {
    	for (int i = 0; i < 10; ++i)
    		countArray[i] = 0;
		for (int i = 0; i < size; ++i)
    		++countArray[(array[i] / exp) % 10];
		for (int i = 1; i < 10; ++i)
    		countArray[i] += countArray[i - 1];
		for (int i = size - 1; i >= 0; --i)
    	{
    		temp[countArray[(array[i] / exp) % 10] - 1] = array[i];
        	--countArray[(array[i] / exp) % 10];
		}
		for (int i = 0; i < size; ++i)
			array[i] = temp[i];
    	exp *= 10;
	}
	delete[] temp;
	end = clock();
	
	printArray(array, size);
	time = (double)(end - begin) / (CLOCKS_PER_SEC / 1000);
	cout << "Running time: " << time << " ms" << endl;
}

void ShakerSort_time(int* array, int size)
{
	clock_t begin, end;
	double time;
	int left = 0, right = size - 1, k = 0;
	
	begin = clock();
	for (int i = left; i <= right; ++i)
	{
		int swapped = 0;
		for (int j = left; j < right; ++j)
			if (array[j] > array[j + 1])
			{
				swapped = 1;
				swap(array[j], array[j + 1]);
				k = j;
			}
		if (!swapped)
			return;
		right = k;
		swapped = 0;
		for (int j = right; j > left; --j)
			if (array[j] < array[j - 1])
			{
				swapped = 1;
				swap(array[j], array[j - 1]);
				k = j;
			}
		if (!swapped)
			return;
		left = k;
	}
	end = clock();
	
	printArray(array, size);
	time = (double)(end - begin) / (CLOCKS_PER_SEC / 1000);
	cout << "Running time: " << time << " ms" << endl;
}

void CountingSort_time(int* array, int size)
{
	clock_t begin, end;
	double time;
	int max = array[0];
		
	begin = clock();
	for (int i = 1; i < size; ++i)
		if (array[i] > max)
			max = array[i];
	int *count = new int[max + 1];
	for (int i = 0; i <= max; ++i)
		count[i] = 0;
	for (int i = 0; i < size; ++i)
		++count[array[i]];
	for (int i = 1; i <= max; ++i)
		count[i] += count[i - 1];

	int *temp = new int[size];
	for (int i = 0; i < size; ++i)
	{
		temp[count[array[i]] - 1] = array[i];
		--count[array[i]];
	}

	for (int i = 0; i < size; ++i)
		array[i] = temp[i];
	delete[] count;
	delete[] temp;
	end = clock();
	
	printArray(array, size);
	time = (double)(end - begin) / (CLOCKS_PER_SEC / 1000);
	cout << "Running time: " << time << " ms" << endl;
}

void FlashSort_time(int* array, int size)
{
	clock_t begin, end;
	double time;
	int minVal = array[0], max = 0, m = int(0.45 * size), * l = new int[m];
	
	
	begin = clock();
	for (int i = 0; i < m; ++i)
		l[i] = 0;
	for (int i = 1; i < size; ++i)
	{
		if (array[i] < minVal)
			minVal = array[i];
		else if (array[i] > array[max])
			max = i;
	}
	if (array[max] == minVal)
	{
		delete[] l;
		return;
	}
	double c1 = (double)(m - 1) / (array[max] - minVal);
	for (int i = 0; i < size; ++i)
	{
		int k = int(c1 * (array[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m; ++i)
		l[i] += l[i - 1];
	swap(array[max], array[0]);
	int nmove = 0, j = 0, k = m - 1, flash;
	while (nmove < size - 1)
	{
		while (j > l[k] - 1)
		{
			++j;
			k = int(c1*(array[j] - minVal));
		}
		flash = array[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1*(flash - minVal));
			--l[k];
			swap(flash, array[l[k]]);
			++nmove;
		}
	}
	delete[] l;
	
	int v, temp = array[0];
	array[0] = -100;
	for (int i = 1; i < size; ++i)
	{
		v = array[i];
		j = i - 1;
		while(array[j] > v)
		{ 
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = v;
	} 
	j = 1;
	while(array[j] < temp)
	{  
		array[j - 1] = array[j];
		++j;
	} 
	array[j - 1] = temp;
	end = clock();
	
	printArray(array, size);
	time = (double)(end - begin) / (CLOCKS_PER_SEC / 1000);
	cout << "Running time: " << time << " ms" << endl;
}

