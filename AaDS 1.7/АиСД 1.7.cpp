#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ifstream filein;
	ofstream fileout;;
	int temp;
	vector<int> arrstart;
	vector<int> arrlis;
	filein.open("input.txt");
	while (filein >> temp) {
		arrstart.push_back(temp);
	}
	int n = arrstart[0];
	arrlis.push_back(arrstart[1]);
	for (int i = 2; i <= n; i++) {
		auto it = lower_bound(arrlis.begin(), arrlis.end(), arrstart[i]);
		if (it == arrlis.end()) {
			arrlis.push_back(arrstart[i]);
		}
		else {
			*it = arrstart[i];
		}
	}
	filein.close();
	fileout.open("output.txt");
	fileout << arrlis.size();

	return 0;
}