#include <iostream>
using namespace std;

void merge(int a[], int s, int q, int e) {
    if (s == q) {
        if (a[s] > a[e]) {
            int temp = a[s];
            a[s] = a[e];
            a[e] = temp;
        }
    } else if (s < q && q < e) {
		int i = s;
		int j = q+1;

		int *b = new int[e - s + 1];
		int index = 0;
		while (i <= q || j <= e) {
            if (i > q) {
                b[index] = a[j];
                j++;
            } else if (j > e) {
                b[index] = a[i];
                i++;
            } else if (a[i] <= a[j]) {
				b[index] = a[i];
				i++;
			} else {
				b[index] = a[j];
				j++;
			}
			//cout << b[index] << " ";
			index++;
		}
        //cout << endl;
		index = 0;
		for (int k = s; k <= e; k++) {
			a[k] = b[index];
			index++;
		}
	}
}

void merge_sort(int a[], int s, int e) {
	if (s < e) {
		int q = (s + e)/2;
		merge_sort(a, s, q);
		merge_sort(a, q+1, e);
		merge(a, s, q, e);
	}
}

int main() {

//    int test[3] = {1, 4, 2};
//    merge(test, 0, 1, 2);
//    for (int i = 0; i < 3; i++)
//        cout << test[i] << " ";
//    cout << endl;

	int n;
	cin >> n;
	int * list = new int[n];
	for (int i = 0; i < n; i++)
		cin >> list[i];
	//merge(list, 0, 4, 9);
    merge_sort(list, 0, n-1);
    for (int j = 0; j < n; j++)
        cout << list[j] << " ";
    cout << endl;

	return 0;
}
