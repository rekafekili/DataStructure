#include<iostream>
using namespace std;

int main(void) {
	int size;
	cout << "Enter a Size : ";
	cin >> size;
	int* arr = new int[size];

	for (int i = 0; i < size; i++) {
		cout << "Fill [" << i << "] : ";
		cin >> arr[i];
	}

	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}