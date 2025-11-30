#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

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
	queue<int> q;
	int metkaNow = 1;
	for (int i = 1; i <= vershCount; i++) {
		if (!visited[i]) {
			visited[i] = true;
			metki[i] = metkaNow;
			metkaNow++;
			q.push(i);
		}
		while (!q.empty()) {
			int temp = q.front();
			q.pop();
			for (int j = 1; j <= vershCount; j++) {
				if (matrix[temp][j] == 1 && !visited[j]) {
					visited[j] = true;
					metki[j] = metkaNow;
					metkaNow++;
					q.push(j);
				}
			}
		}
	}
	for (int i = 1; i <= vershCount; i++) {
		fileout << metki[i] << " ";
	}
	for (int i = 0; i <= vershCount; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	filein.close();
	fileout.close();
	return 0;
}