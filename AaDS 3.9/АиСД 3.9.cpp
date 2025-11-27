#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main() {
    ifstream filein("input.txt");
    ofstream fileout("output.txt");
    int count;
    filein >> count;
    if (count % 2 == 0) {
        stack<int> shlangi;
        for (int i = 0; i < count; i++) {
            double x, y;
            int upShlang;
            filein >> x >> y >> upShlang;
            if (!shlangi.empty() && shlangi.top() == upShlang) {
                shlangi.pop();
            }
            else {
                shlangi.push(upShlang);
            }
        }
        if (shlangi.empty()) {
            fileout << "Yes";
        }
        else {
            fileout << "No";
        }
    }
    else {
        fileout << "No";
    }
    filein.close();
    fileout.close();
    return 0;
}