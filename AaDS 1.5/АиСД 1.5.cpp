#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arri(n), arrj(n);
	for (int i = 0; i < n; i++) {
		cin >> arri[i];
	}
	for (int j = 0; j < n; j++) {
		cin >> arrj[j];
	}

	int** matrix = new int* [n + 1];
	for (int i = 0; i <= n; i++) {
		matrix[i] = new int[n + 1];
	}

	for (int j = 0; j <= n; j++) {
		matrix[0][j] = 0;
	}
	for (int i = 0; i <= n; i++) {
		matrix[i][0] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arri[i - 1] == arrj[j - 1]) {
				matrix[i][j] = matrix[i - 1][j - 1] + 1;
			}
			else {
				matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
			}
		}
	}
	cout << matrix[n][n] << endl;

	vector <int> nopi;
	vector <int> nopj;
	int i = n;
	int j = n;
	while (i > 0 && j > 0 && matrix[i][j] != 0) {
		if (arri[i - 1] == arrj[j - 1]) {
			nopi.push_back(i - 1);
			nopj.push_back(j - 1);
			i--;
			j--;
		}
		else if (matrix[i][j - 1] == matrix[i][j]) {
			j--;
		}
		else if (matrix[i - 1][j] == matrix[i][j]) {
			i--;
		}
	}
	reverse(nopi.begin(), nopi.end());
	reverse(nopj.begin(), nopj.end());
	for (int i = 0; i < nopi.size(); i++) {
		cout << nopi[i] << " ";
	}
	cout << endl;
	for (int j = 0; j < nopj.size(); j++) {
		cout << nopj[j] << " ";
	}

	for (int i = 0; i <= n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}