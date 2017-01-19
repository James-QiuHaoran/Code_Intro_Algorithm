#include <iostream>
using namespace std;

struct Array {
	int start;
	int end;
	int sum;
};

Array findMaxSubarray(int a[], int low, int high) {
	if (low == high) {// there is only one element
		Array result;
		result.start = low;
		result.end = high;
		result.sum = a[low];
		return result;
	} else {
		int mid = (low + high)/2;
		Array left = findMaxSubarray(a, low, mid);
		Array right = findMaxSubarray(a, mid + 1, high);
		Array crossing;
		int leftsum = -9999999;
		int rightsum = -9999999;
		int sum = 0;
		for (int i = mid; i >= low; i--) {
			sum += a[i];
			if (sum >= leftsum) {
				leftsum = sum;
				crossing.start = i;
			}
		}
		sum = 0;
		for (int i = mid+1; i <= high; i++) {
			sum += a[i];
			if (sum >= rightsum) {
				rightsum = sum;
				crossing.end = i;
			}
		}
		sum = 0;
		for (int i = crossing.start; i <= crossing.end; i++) {
			sum += a[i];
		}
		crossing.sum = sum;

		if (left.sum >= right.sum && left.sum >= crossing.sum)
			return left;
		else if (right.sum >= left.sum && right.sum >= crossing.sum)
			return right;
		else return crossing;
	}
}

int main() {
	int n;
	cin >> n;
	int *list = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	Array sublist = findMaxSubarray(list, 0, n-1);
	for (int i = sublist.start; i <= sublist.end; i++)
		cout << list[i] << " ";
	cout << endl;

	return 0;
}
