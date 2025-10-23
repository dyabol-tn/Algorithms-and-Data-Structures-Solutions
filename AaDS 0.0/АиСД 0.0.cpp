#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main() {
	string inputName = "input.txt";
	string outputName = "output.txt";
	long long sum = 0;
	ifstream fileIn;
	fileIn.open(inputName);
	set<int> newSet;
	int nums;
	while (fileIn >> nums) {
		newSet.insert(nums);
	}
	fileIn.close();
	for (int i : newSet) {
		sum += i;
	}
	ofstream fileOut;
	fileOut.open(outputName);
	fileOut << sum;
	fileOut.close();
	return 0;
}
