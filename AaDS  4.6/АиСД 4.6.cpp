#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void dfs(int i, int** matrix, vector<bool>& visited, vector<int>& metki, int& metkaNow, int vershCount) {
	visited[i] = true;
	metki[i] = metkaNow;
	metkaNow++;
	for (int j = 1; j <= vershCount; j++) {
		if (matrix[i][j] == 1 && !visited[j]) {
			dfs(j, matrix, visited, metki, metkaNow, vershCount);
		}
	}
}

int main() {
	ifstream filein("input.txt");
	ofstream fileout("output.txt");
	int vershCount;
	filein >> vershCount;
	int** matrix = new int* [vershCount + 1];
	for (int i = 0; i <= vershCount; i++) {
		matrix[i] = new int[vershCount + 1];
	}
	for (int i = 1; i <= vershCount; i++) {
		for (int j = 1; j <= vershCount; j++) {
			filein >> matrix[i][j];
		}
	}
	vector<bool> visited(vershCount + 1, false);
	vector<int> metki(vershCount + 1, -1);
	int metkaNow = 1;
	for (int i = 1; i <= vershCount; i++) {
		if (!visited[i]) {
			dfs(i, matrix, visited, metki, metkaNow, vershCount);
		}
	}
	for (int i = 1; i <= vershCount; i++) {
		cout << metki[i] << " ";
	}
	for (int i = 0; i <= vershCount; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	filein.close();
	fileout.close();
	return 0;
}