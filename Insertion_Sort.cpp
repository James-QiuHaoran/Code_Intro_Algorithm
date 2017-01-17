#include <iostream>
using namespace std;

int* insertion_sort(int a[], int n) {
	for (int j = 1; j < n; j++) {
		int key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] > key) {
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = key;
	}
	return a;
}

int main() {
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int *b = insertion_sort(a, n);
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << endl;

	return 0;
}
