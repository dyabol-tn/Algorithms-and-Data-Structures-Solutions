#include <iostream>

using namespace std;

int binarySearch(int arr[], int srch, int low, int up) {
	if (low > up) return -1;
	int mid = (low + up) / 2;
	if (arr[mid] == srch) return mid;
	if (arr[mid] > srch) return binarySearch(arr, srch, low, mid - 1);
	else return binarySearch(arr, srch, mid + 1, up);
}

int upperBound(int arr[], int srch, int low, int up) {
	if (low >= up) return low;
	int mid = (low + up) / 2;
	if (arr[mid] <= srch) return upperBound(arr, srch, mid + 1, up);
	else return upperBound(arr, srch, low, mid);
}

int lowerBound(int arr[], int srch, int low, int up) {
	if (low >= up) return low;
	int mid = (low + up) / 2;
	if (arr[mid] < srch) return lowerBound(arr, srch, mid + 1, up);
	else return lowerBound(arr, srch, low, mid);
}

int main() {
	int n, k;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cin >> k;
	int* arrK = new int[k];
	for (int i = 0; i < k; i++) {
		cin >> arrK[i];
	}

	for (int i = 0; i < k; i++) {
		int resB = binarySearch(arr, arrK[i], 0, n - 1);
		if (resB != -1) cout << 1 << " ";
		else cout << 0 << " ";

		int resL = lowerBound(arr, arrK[i], 0, n);
		cout << resL << " ";

		int resR = upperBound(arr, arrK[i], 0, n);
		cout << resR << endl;
	}

	delete[] arrK;
	delete[] arr;
	return 0;
}