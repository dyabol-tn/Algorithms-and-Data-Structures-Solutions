#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> arr(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	if (n == 1) {
		cout << arr[1] << endl << 1;
		return 0;
	}

	vector <int>  F(n + 1, -1);
	vector <int> pr(n + 1, -1);

	F[1] = arr[1];
	F[2] = -1;

	for (int i = 1; i <= n; i++) {
		if (F[i] == -1) continue;
		if (i + 2 <= n) {
			F[i + 2] = max(F[i + 2], F[i] + arr[i + 2]);
			if (F[i + 2] == F[i] + arr[i + 2]) {
				pr[i + 2] = i;
			}
		}
		if (i + 3 <= n) {
			F[i + 3] = max(F[i + 3], F[i] + arr[i + 3]);
			if (F[i + 3] == F[i] + arr[i + 3]) {
				pr[i + 3] = i;
			}
		}
	}

	if (F[n] == -1) {
		cout << -1;
		return 0;
	}

	cout << F[n] << endl;

	int temp = n;
	vector <int> path;
	while (temp != -1) {
		path.push_back(temp);
		if (temp == 1) break;
		temp = pr[temp];
	}
	reverse(path.begin(), path.end());
	for (int i = 0; i < path.size(); i++) {
		cout << path[i] << " ";
	}

	return 0;
}