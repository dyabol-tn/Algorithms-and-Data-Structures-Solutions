#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream filein("input.txt");
	ofstream fileout("output.txt");
	int vershCount, rebrCount;
	filein >> vershCount >> rebrCount;
	int** vershins = new int* [vershCount + 1];
	for (int i = 0; i <= vershCount; i++) {
		vershins[i] = new int[vershCount + 1];
	}
	for (int i = 0; i <= vershCount; i++) {
		for (int j = 0; j <= vershCount; j++) {
			vershins[i][j] = 0;
		}
	}
	int first, second;
	while (filein >> first >> second) {
		vershins[first][second] = 1;
		vershins[second][first] = 1;
	}
	for (int i = 1; i <= vershCount; i++) {
		for (int j = 1; j <= vershCount; j++) {
			fileout << vershins[i][j] << " ";
		}
		fileout << endl;
	}
	filein.close();
	fileout.close();
	for (int i = 0; i <= vershCount; i++) {
		delete[] vershins[i];
	}
	delete[] vershins;
	return 0;
}