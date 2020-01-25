
#include "pch.h"
#include <iostream>

//Function: swap
//Description: swaps two items in stack.
//Parameters: a (pointer to first item to swap), b (pointer to second item).
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//Function: printArray
//Parameters: arr (the array to be sorted). low (the lowest index to look at). high (the highest index to look at)
//Description: recursively sorts the array by calling partition and separating into sub arrays.
int partition(int arr[], int low, int high)
{
	int pivot, left, right, 
	int j, i; //i will be the smaller element, while j will be the larger element to compare later

	pivot = arr[high];
	i = low - 1;

	//here we are essentially getting the index of the pivot
	for (j = low; j <= high; j++)
	{
		if (arr[j] < pivot) //check if element at j is lesser than pivot.
		{
			i = i + 1; //increment the smaller element
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[high]); //swap i + 1 with the pivot.
	return i + 1; //return the index for the next partition.
}

//Function: printArray
//Parameters: arr (the array to be sorted). low (the lowest index to look at). high (the highest index to look at)
//Description: recursively sorts the array by calling partition and separating into sub arrays.
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int p = partition(arr, low, high);

		quickSort(arr, low, p - 1); //call quick sort on the lower partition
		quickSort(arr, p + 1, high); //call quick sort on the higher partition
	}
}

//Function: printArray
//Parameters: arr (the array to be printed). size (the number of elements in said array).
//Description: prints the array passed to it.
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++) //iterate through each elements in the array
		std::cout << arr[i] << " ";
}

int main()
{
	int arr[10] = { 1, 6, 2, 5, 7, 3, 6, 12, 3, 19 };
	int elm = sizeof(arr) / sizeof(arr[0]); //get the number of elements in the array

	quickSort(arr, 0, elm - 1);
	printArray(arr, elm);
	return 0;
}
