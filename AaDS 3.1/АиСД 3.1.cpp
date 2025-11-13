#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream filein("input.txt");
	ofstream fileout("output.txt");
	int size;
	filein >> size;
	vector<int> arr(size + 1);
	bool check = true;
	for (int i = 1; i <= size; i++) {
		filein >> arr[i];
	}
	for (int i = 1; i <= size / 2; i++) {
		if ((2 * i <= size && arr[i] > arr[2 * i]) || (2 * i + 1 <= size && arr[i] > arr[2 * i + 1])) {
			check = false;
			break;
		}
	}
	if (check) fileout << "Yes";
	else fileout << "No";
	filein.close();
	fileout.close();
	return 0;
}