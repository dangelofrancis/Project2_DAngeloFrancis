//************************************************
// TITLE: Reverse Array                          *
// FILE NAME: Project1_DAngeloFrancis.cpp        *
// PROGRAMMER: D'Angelo Francis                  *
// DATE: February 24th, 2025                     *
// REQUIREMENTS: Dynamically create an array and *
// reverse its contents                          *
//************************************************

#include <iostream>
using namespace std;

//************************************************
// Description of the function reverseArray      *
// This function take the original array, it     *
// reverses it, and then returns the reverse     *
//************************************************

int* reverseArray(const int arr[], int size);

//************************************************
// Description of the function print             *
// This function displays the original and       *
// reversed arrays on screen                     *
//************************************************

void print(const int arr[], int size);

int main()
{
	const int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size = 10;

	int* reverseArr = reverseArray(arr, size);

	cout << "Original Array: \n";
	print(arr, size);
	cout << endl;
	cout << "Reversed Array: \n";
	print(reverseArr, size);

	delete[] reverseArr;

	return 0;
}
int* reverseArray(const int arr[], int size) {
	int* reverseArr = new int[size];

	for (int count = 0; count < size; count++) {
		reverseArr[count] = arr[size - 1 - count];
	}

	return reverseArr;
}
void print(const int arr[], int size) {
	for (int count = 0; count < size; count++) {
		cout << arr[count] << " ";
	}
	cout << endl;
}