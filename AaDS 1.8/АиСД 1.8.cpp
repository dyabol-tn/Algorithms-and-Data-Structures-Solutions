#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ifstream filein;
	ofstream fileout;
	filein.open("in.txt");
	int x, y, z;
	string A, B;
	filein >> x >> y >> z;
	filein >> A >> B;

	int** F = new int* [A.length() + 1];
	for (int i = 0; i <= A.length(); i++) {
		F[i] = new int[B.length() + 1];
	}
	for (int i = 0; i <= A.length(); i++) {
		F[i][0] = i * x;
	}
	for (int j = 0; j <= B.length(); j++) {
		F[0][j] = j * y;
	}
	for (int i = 1; i <= A.length(); i++) {
		for (int j = 1; j <= B.length(); j++) {
			int delta;
			if (A[i - 1] == B[j - 1]) {
				delta = 0;
			}
			else {
				delta = 1;
			}
			F[i][j] = min({ F[i - 1][j] + x, F[i][j - 1] + y, F[i - 1][j - 1] + delta * z });
		}
	}
	fileout.open("out.txt");
	fileout << F[A.length()][B.length()];
	filein.close();
	fileout.close();
	for (int i = 0; i <= A.length(); i++) {
		delete[] F[i];
	}
	delete[] F;
	return 0;
}