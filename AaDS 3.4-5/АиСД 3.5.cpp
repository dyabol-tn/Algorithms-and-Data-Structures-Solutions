#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct DSU {
	int first;
	int second;

	int FindSet(vector<int>& arr, int x) {
		while (arr[x] > 0) x = arr[x];
		return x;
	}

	int Union(vector<int>& parent, int first, int second, int city) {
		int x = FindSet(parent, first);
		int y = FindSet(parent, second);
		if (x == y) return city;
		else if (parent[x] < parent[y]) {
			parent[x] += parent[y];
			parent[y] = x;
			city--;
			return city;
		}
		else {
			parent[y] += parent[x];
			parent[x] = y;
			city--;
			return city;
		}
	}
};



int main() {
	DSU dsu;
	int city, roads, eqsCount, citysvyaz;
	ifstream filein("input.txt");
	ofstream fileout("output.txt");
	filein >> city >> roads >> eqsCount;
	citysvyaz = city;
	vector<DSU> arr(roads + 1);
	vector<int> parent(city + 1, -1);
	vector<int> eqs(roads + 1, -1);
	vector<int> eqs1(eqsCount);
	vector<bool> res;
	for (int i = 1; i <= roads; i++) {
		int fir, sec;
		filein >> fir >> sec;
		arr[i].first = fir;
		arr[i].second = sec;
	}
	for (int i = 0; i < eqsCount; i++) {
		int temp;
		filein >> temp;
		eqs[temp] = temp;
		eqs1[i] = temp;
	}
	for (int i = 1; i <= roads; i++) {
		if (eqs[i] == -1) {
			citysvyaz = dsu.Union(parent, arr[i].first, arr[i].second, citysvyaz);
		}
	}

	for (int i = eqsCount - 1; i >= 0; i--) {
		res.push_back(citysvyaz == 1);
		int k = eqs1[i];
		citysvyaz = dsu.Union(parent, arr[k].first, arr[k].second, citysvyaz);
		if (citysvyaz == 1) {
			for (int j = 0; j < i; j++) {
				res.push_back(true);
			}
			break;
		}
	}
	for (int i = res.size() - 1; i >= 0; i--) {
		fileout << (res[i] ? '1' : '0');
	}
	filein.close();
	fileout.close();
	return 0;
}