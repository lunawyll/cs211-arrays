#include <iostream>
#include "arrays.h"

using namespace std;

int main(){
	task_1();
	task_2();
	cout << task_3_zero() << endl;
	task_4();
	
	const int n = 5;
	int arr1[]{1,2,3,4,5};
	int arr2[]{0, 1, 3, 4, -4};
	cout << "Copy test\nFirst:\n";

	for (int i = 0; i < n; i++)
		cout << arr1[i] << ' ';
	cout << endl;
	task_5_copy(arr1, arr2, n);
	cout << "Second:\n";
	for (int i = 0; i < n; i++)
		cout << arr2[i] << ' ';
	cout << endl;
 
	cout << "Poor copy test\nFirst:\n";
	arr1[1] = 100;
	for (int i = 0; i < n; i++)
		cout << arr1[i] << ' ';
	cout << endl;
	task_5_copy(arr1, arr2, n);
	cout << "Second:\n";
	for (int i = 0; i < n; i++)
		cout << arr2[i] << ' ';
	cout << endl;

	return 0;
}