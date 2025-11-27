#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream filein("input.txt");
	ofstream fileout("output.txt");
	int size;
	filein >> size;
	int* graf = new int[size + 1];
	for (int i = 0; i <= size; i++) {
		graf[i] = 0;
	}
	int first, second;
	while (filein >> first >> second) {
		graf[second] = first;
	}
	for (int i = 1; i <= size; i++) {
		fileout << graf[i] << " ";
	}
	filein.close();
	fileout.close();
	delete[] graf;
	return 0;
}