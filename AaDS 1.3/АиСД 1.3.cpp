/*#include <iostream>

using namespace std;

int main() {
	int mod = 10e9 + 7;
	int N, K;
	cin >> N >> K;
	int* arr = new int[K + 1];

	for (int i = 0; i <= K; i++) {
		arr[i] = 0;
	}

	arr[0] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = K; j >= 1; j--) {
			arr[j] = (arr[j] + arr[j - 1]) % mod;
		}
	}

	cout << arr[K];
	delete[] arr;
	return 0;
}*/

#include <iostream>

using namespace std;

long long F(long long b, long long n, const int mod) {
	if (n == 1) return b;
	if (n == 0) return 1;
	long long t;
	if (n % 2 == 0) {
		t = F(b, (n / 2), mod);
		return ((t % mod) * (t % mod)) % mod;
	}
	else {
		t = F(b, (n - 1) / 2, mod);
		return ((t % mod) * (t % mod) % mod) * (b % mod) % mod;
	}
}

long long calcBinomial(int N, int K, const int mod) {
	if (K == N || K == 0) return 1;
	long long product = 1;
	for (int i = 1; i <= K; i++) {
		product = (product * (N - i + 1) % mod) * (F(i, mod - 2, mod) % mod) % mod;
	}
	return product;
}

int main() {

	const int mod = 1e9 + 7;
	int N, K;
	cin >> N >> K;
	if (K > N - K) K = N - K;
	cout << calcBinomial(N, K, mod);
	return 0;
}

/*#include <iostream>

using namespace std;

long long degree(int a, int d, int mod) {
	if (d == 1) return a;
	if (d == 0) return 1;

	long long prom;
	if (d % 2 == 0) {
		prom = degree(a, d / 2, mod);
		return ((prom % mod) * (prom % mod)) % mod;
	}
	else {
		prom = degree(a, (d - 1) / 2, mod);
		return ((((prom % mod) * (prom % mod)) % mod) * (a % mod)) % mod;
	}

}

long long calculateC(int n, int k, int mod) {
	long long result = 1;
	for (int i = 1; i <= n - k; i++) {
		result = ((result * ((i + k) % mod) % mod) * (degree(i, mod - 2, mod) % mod)) % mod;
	}
	return result;
}

int main()
{
	int n, k, mod = 1000000007;
	cin >> n >> k;
	if (k < n - k) k = n - k;
	cout << calculateC(n, k, mod);
	return 0;
}*/