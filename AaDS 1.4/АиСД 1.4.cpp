#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	ifstream filein;
	ofstream fileout;
	filein.open("input.txt");
	int s;
	filein >> s;
	int** matrix = new int* [s];
	for (int i = 0; i < s; i++) {
		matrix[i] = new int[2];
	}
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < 2; j++) {
			filein >> matrix[i][j];
		}
	}
	filein.close();

	int** F = new int* [s];
	for (int i = 0; i < s; i++) {
		F[i] = new int[s];
	}

	for (int i = 0; i < s; i++) {
		F[i][i] = 0;
	}

	for (int len = 2; len <= s; len++) {
		for (int i = 0; i <= s - len; i++) {
			int j = i + len - 1;
			F[i][j] = INT_MAX;
			for (int k = i; k < j; k++) {
				int cost = F[i][k] + F[k + 1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1];
				F[i][j] = min(F[i][j], cost);
			}
		}
	}
	fileout.open("output.txt");
	fileout << F[0][s - 1];
	fileout.close();

	for (int i = 0; i < s; i++) {
		delete[] matrix[i];
		delete[] F[i];
	}
	delete[] matrix;
	delete F;
	return 0;
}