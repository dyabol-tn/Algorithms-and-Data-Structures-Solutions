#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream filein("input.txt");
	ofstream fileout("output.txt");
	int vershCount, rebrCount;
	filein >> vershCount >> rebrCount;
	vector<int> podList(vershCount + 1, 0);
	vector<int> first(rebrCount);
	vector<int> second(rebrCount);
	for (int i = 0; i < rebrCount; i++) {
		filein >> first[i] >> second[i];
		podList[first[i]]++;
		podList[second[i]]++;
	}
	int** list = new int* [vershCount + 1];
	for (int i = 1; i <= vershCount; i++) {
		list[i] = new int[podList[i]];
		podList[i] = 0;
	}
	for (int i = 0; i < rebrCount; i++) {
		list[first[i]][podList[first[i]]++] = second[i];
		list[second[i]][podList[second[i]]++] = first[i];
	}
	for (int i = 1; i <= vershCount; i++) {
		fileout << podList[i];
		for (int j = 0; j < podList[i]; j++) {
			fileout << " " << list[i][j];
		}
		fileout << endl;
	}
	for (int i = 1; i <= vershCount; i++) {
		delete[] list[i];
	}
	delete[] list;
	return 0;
}