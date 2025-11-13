#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int FindSet(vector<int>& arr, int x) {
	while (arr[x] > 0) x = arr[x];
	return x;
}

int Union(vector<int>& arr, int first, int second, int city) {
	int x = FindSet(arr, first);
	int y = FindSet(arr, second);
	if (x == y) return city;
	else if (arr[x] < arr[y]) {
		arr[x] += arr[y];
		arr[y] = x;
		city--;
		return city;
	}
	else {
		arr[y] += arr[x];
		arr[x] = y;
		city--;
		return city;
	}
}

int main() {
	int city, req;
	ifstream filein("input.txt");
	ofstream fileout("output.txt");
	filein >> city >> req;
	vector<int> arr(city + 1, -1);
	for (int i = 0; i < req; i++) {
		int first, second;
		filein >> first >> second;
		city = Union(arr, first, second, city);
		fileout << city << endl;
	}
	return 0;
}