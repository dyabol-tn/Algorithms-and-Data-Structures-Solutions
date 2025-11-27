#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream filein("input.txt");
	ofstream fileout("output.txt");
	int size;
	filein >> size;
	bool** matrix = new bool* [size + 1];
	for (int i = 0; i <= size; i++) {
		matrix[i] = new bool[size + 1];
	}
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			int temp;
			filein >> temp;
			matrix[i][j] = temp;
		}
	}
	vector<int> kanon(size + 1, 0);
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			if (matrix[i][j] == 1) {
				kanon[j] = i;
			}
		}
	}
	for (int i = 1; i <= size; i++) {
		fileout << kanon[i] << " ";
	}
	for (int i = 0; i <= size; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	filein.close();
	fileout.close();
	return 0;
}