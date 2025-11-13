#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*class Node {
public:
	long long val;
	int left = -1;
	int right = -1;
};

bool BSTCheck(vector<Node>& bst, int i, long long minV, long long maxV) {
	if (i == -1) return true;
	if (bst[i].val <= minV || bst[i].val > maxV) return false;
	return BSTCheck(bst, bst[i].left, minV, bst[i].val) && BSTCheck(bst, bst[i].right, bst[i].val, maxV);
}

int main() {
	ifstream filein("bst.in");
	ofstream fileout("bst.out");
	int count;
	filein >> count;
	vector<Node> bst(count + 1);
	filein >> bst[1].val;
	for (int i = 2; i <= count; i++) {
		long long m;
		int p;
		char c;
		filein >> m >> p >> c;
		bst[i].val = m;
		if (c == 'L') {
			bst[p].left = i;
		}
		else if (c == 'R') {
			bst[p].right = i;
		}
	}
	bool res = BSTCheck(bst, 1, LLONG_MIN, LLONG_MAX);
	if (res) cout << "YES";
	else cout << "NO";
	return 0;
}*/

class Node {
public:
    long long value;
    long long minV;
    long long maxV;
    int left = -1;
    int right = -1;

    Node() : value(0), minV(0), maxV(0) {};
    Node(long long val, long long min_b, long long max_b) : value(val), minV(min_b), maxV(max_b) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream filein("bst.in");
    ofstream fileout("bst.out");
    int count;
    filein >> count;
    if (count == 0) {
        fileout << "YES";
        return 0;
    }
    vector<Node> bst(count + 1);
    filein >> bst[1].value;
    bst[1].minV = LLONG_MIN;
    bst[1].maxV = LLONG_MAX;
    for (int i = 2; i <= count; i++) {
        long long m;
        int p;
        char c;
        filein >> m >> p >> c;
        bst[i].value = m;
        if (c == 'L') {
            bst[p].left = i;
            if (m >= bst[p].value) {
                fileout << "NO";
                return 0;
            }
            bst[i].minV = bst[p].minV;
            bst[i].maxV = bst[p].value - 1;
        }
        else {
            bst[p].right = i;
            if (m < bst[p].value) {
                fileout << "NO";
                return 0;
            }
            bst[i].minV = bst[p].value;
            bst[i].maxV = bst[p].maxV;
        }
        if (m < bst[i].minV || m > bst[i].maxV) {
            fileout << "NO";
            return 0;
        }
    }
    fileout << "YES";
    return 0;
}