#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

long long FindSum(vector <long long>& arrA, vector<long long>& arrB, int l, int r, int sizek) {
	long long sum = 0;
	int lk = l / sizek, rk = r / sizek;
	if (lk == rk) {
		for (int i = l; i < r; i++) {
			sum += arrA[i];
		}
		return sum;
	}
	else {
		for (int i = l; i < (lk + 1) * sizek; i++) {
			sum += arrA[i];
		}
		for (int i = lk + 1; i < rk; i++) {
			sum += arrB[i];
		}
		for (int i = rk * sizek; i < r; i++) {
			sum += arrA[i];
		}
		return sum;
	}
}

void Add(vector<long long>& arrA, vector<long long>& arrB, int index, long long x, int sizek) {
	arrA[index] += x;
	arrB[index / sizek] += x;
}

int main() {
	int sizen, reqCount;
	cin >> sizen;
	vector<long long> arrA(sizen);
	int sizek = sqrt(sizen) + 1;
	vector<long long> arrB(sizek, 0);
	for (int i = 0; i < sizen; i++) {
		cin >> arrA[i];
	}
	cin >> reqCount;
	for (int i = 0; i < sizen; i++) {
		arrB[i / sizek] += arrA[i];
	}
	for (int i = 0; i < reqCount; i++) {
		string req;
		cin >> req;
		if (req == "FindSum") {
			int l, r;
			cin >> l >> r;
			cout << FindSum(arrA, arrB, l, r, sizek) << endl;
		}
		if (req == "Add") {
			int index;
			long long x;
			cin >> index >> x;
			Add(arrA, arrB, index, x, sizek);
		}
	}
	return 0;
}