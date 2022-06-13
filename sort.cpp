#include "sort.h"

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
	
	cout << "Comparisions: " << countCompare << endl;
}

