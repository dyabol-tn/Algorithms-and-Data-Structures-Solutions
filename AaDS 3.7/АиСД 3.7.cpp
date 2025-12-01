#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream filein("input.txt");
	ofstream fileout("output.txt");
	int tableSize, keysCount, constC;
	filein >> tableSize >> constC >> keysCount;
	vector<int> keys(tableSize, -1);
	for (int i = 0; i < keysCount; i++) {
		int key; 
		filein >> key;
		bool find = false;
		for (int i = 0; i < tableSize; i++) {
			int h = ((key % tableSize) + constC * i) % tableSize;
			if (keys[h] == key) {
				find = true;
				break;
			}
		}
		if (find) continue;
		for (int i = 0; i < tableSize; i++) {
			int h = ((key % tableSize) + constC * i) % tableSize;
			if (keys[h] == -1) {
				keys[h] = key;
				break;
			}
		}
	}
	for (int i = 0; i < tableSize; i++) {
		fileout << keys[i] << " ";
	}
	filein.close();
	fileout.close();
	return 0;
}