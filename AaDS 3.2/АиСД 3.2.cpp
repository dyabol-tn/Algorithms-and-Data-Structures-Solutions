#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream filein("huffman.in");
	ofstream fileout("huffman.out");
	int n;
	filein >> n;
	vector<int>arr(n);
	vector<long long>arrPar;
	for (int i = 0; i < n; i++) {
		filein >> arr[i];
	}
	long long left, right, sum = 0;
	int i = 0, j = 0;
	for (int k = 0; k < n - 1; k++) {
		if (i < n && (j >= arrPar.size() || arr[i] < arrPar[j])) {
			left = arr[i];
			i++;
		}
		else {
			left = arrPar[j];
			j++;
		}
		if (i < n && (j >= arrPar.size() || arr[i] < arrPar[j])) {
			right = arr[i];
			i++;
		}
		else {
			right = arrPar[j];
			j++;
		}
		long long parent = left + right;
		sum += parent;
		arrPar.push_back(parent);
	}
	fileout << sum;
	filein.close();
	fileout.close();
	return 0;
}