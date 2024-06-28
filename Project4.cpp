#include <iostream>
#include <string>
#include "searchSortAlgorithms.h"
#include <ctime>
#include <cstdlib>

using namespace std;

void print(int list[], int length);

int main()
{
	clock_t t = clock();
	srand(time(0));
	int a[10000];
	for (int i = 0; i < 10000; i++) {
		a[i] = rand() % 10000;
	}
	cout << "CPU Time: " << static_cast<int>(clock()) - static_cast<int>(t) << endl;
	t = clock();
	cout << "First 10 elements of the array (unsorted): ";
	print(a, 10);
	quickSort(a, 10000);
	cout << "CPU Time: " << static_cast<int>(clock()) - static_cast<int>(t) << endl;
	cout << "First 10 elements of the array (sorted): ";
	print(a, 10);
	return 0;
}
void print(int list[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}
