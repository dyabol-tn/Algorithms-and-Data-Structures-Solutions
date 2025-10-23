#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream filein;
	ofstream fileout;
	filein.open("input.txt");
	vector<char> arri;
	char temp;
	while (filein >> temp) {
		arri.push_back(temp);
	}
	int n = arri.size();

	int** F = new int* [n];
	for (int i = 0; i < n; i++) {
		F[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		F[i][i] = 1;
	}

	for (int i = 0; i < n - 1; i++) {
		if (arri[i] == arri[i + 1]) {
			F[i][i + 1] = 2;
		}
		else {
			F[i][i + 1] = 1;
		}
	}

	for (int len = 3; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {
			int j = i + len - 1;
			if (arri[i] == arri[j]) {
				F[i][j] = F[i + 1][j - 1] + 2;
			}
			else {
				F[i][j] = max(F[i + 1][j], F[i][j - 1]);
			}
		}
	}
	string left, right;
	int i = 0, j = n - 1;
	while (i <= j) {
		if (arri[i] == arri[j]) {
			left += arri[i];
			if (i != j) right = arri[j] + right;
			i++;
			j--;
		}
		else if (F[i + 1][j] >= F[i][j - 1]) {
			i++;
		}
		else {
			j--;
		}
	}
	string result = left + right;
	fileout.open("output.txt");
	fileout << F[0][n - 1] << endl;
	fileout << result.c_str();
	filein.close();
	fileout.close();
	for (int i = 0; i < n; i++) {
		delete[] F[i];
	}
	delete[] F;
	return 0;
}