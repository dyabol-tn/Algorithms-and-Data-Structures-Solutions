#include <iostream>

using namespace std;

int main() {
	const int mod = 1e9 + 7;
	int N, K;
	cin >> N >> K;

	int** arr = new int* [N + 1];
	for (int i = 0; i <= N; i++) {
		arr[i] = new int[K + 1];
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			arr[i][j] = 0;
		}
	}

	arr[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			arr[i + 1][j] = (arr[i + 1][j] + arr[i][j]) % mod;
			if (j + 1 <= K) {
				arr[i + 1][j + 1] = (arr[i + 1][j + 1] + arr[i][j]) % mod;
			}
		}
	}

	cout << arr[N][K];

	for (int i = 0; i <= N; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}