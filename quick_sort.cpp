#include <iostream>
#include <ctime>
#include <cstdlib>
 
using namespace std;
 
// pivot - "опорный" элемент
// partition - переупорядочивает элементы части массива,
// заданной отрезком [left, right), так что в начале
// следуют элементы меньшие pivot, а в конце  - большие;
// возвращает место pivot;
int * partition(int * left, int *  right, int pivot) {
	int * store = left; // место для вставки элементов, меньших pivot
	for (int * p = left; p != right; ++p)
		if (*p < pivot)
			swap(*p, *store++);
	return store;
}
 

void my_qsort(int * arr, int n) {
	if (n <= 1)
		return; // массив в 1 или 0 элементов уже упорядочен
	int * pivotPtr = arr + rand() % n; // случайный выбор опорного элемента
	swap(arr[n - 1], *pivotPtr);
	int newPivotIdx = partition(arr, arr + n, arr[n - 1]) - arr;
	swap(arr[newPivotIdx], arr[n - 1]);
	my_qsort(arr, newPivotIdx);
	my_qsort(arr + newPivotIdx + 1, n - (newPivotIdx + 1));
}


int main(){
	srand((unsigned)time(0));
	const int n = 10;
	//int a[n] {4, 5, 2, 7, 1};
	int a[n];
	
	for (int i = 0; i < n; i++){
		a[i] = rand() % 100;
	}
	
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	my_qsort(a, n);
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}