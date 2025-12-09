#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ifstream filein("input.txt");
    ofstream fileout("output.txt");
    int size;
    filein >> size;
    bool** graf = new bool* [size];
    for (int i = 0; i < size; i++) {
        graf[i] = new bool[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            graf[i][j] = 0;
        }
    }
    for (int i = 0; i < size; i++) {
        int versh;
        while (filein >> versh && versh != -2) {
            graf[i][versh] = 1;
        }
    }
    vector<int> neizbVersh;
    for (int i = 1; i < size - 1; i++) {
        vector<bool> visited(size, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        bool check = false;
        while (!q.empty() && !check) {
            int now = q.front();
            q.pop();
            if (now == size - 1) {
                check = true;
                break;
            }
            for (int j = 0; j < size; j++) {
                if (graf[now][j] && j != i && !visited[j]) {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
        if (!check) {
            neizbVersh.push_back(i);
        }
    }
    sort(neizbVersh.begin(), neizbVersh.end());

    bool** dostizhMatrix = new bool* [size];
    for (int i = 0; i < size; i++) {
        dostizhMatrix[i] = new bool[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            dostizhMatrix[i][j] = false;
        }
    }
    for (int i = 0; i < neizbVersh.size(); i++) {
        int s = neizbVersh[i];
        queue<int> q;
        q.push(s);
        dostizhMatrix[s][s] = true;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int j = 0; j < size; j++) {
                if (graf[now][j] && !dostizhMatrix[s][j]) {
                    dostizhMatrix[s][j] = true;
                    q.push(j);
                }
            }
        }
    }
    vector<int> razbVersh;
    for (int i = 0; i < neizbVersh.size(); i++) {
        int s = neizbVersh[i];
        vector<bool> visited(size, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int j = 0; j < size; j++) {
                if (j == s) continue;
                if (graf[now][j] && !visited[j]) {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
        bool check = false;
        for (int k = 0; k < size; k++) {
            if (k != s && dostizhMatrix[s][k] && visited[k]) {
                check = true;
            }
        }
        if (!check) {
            razbVersh.push_back(s);
        }
    }
    sort(razbVersh.begin(), razbVersh.end());

    fileout << neizbVersh.size() << " ";
    for (int i = 0; i < neizbVersh.size(); i++) {
        fileout << neizbVersh[i] << " ";
    }
    fileout << endl;
    fileout << razbVersh.size() << " ";
    for (int i = 0; i < razbVersh.size(); i++) {
        fileout << razbVersh[i] << " ";
    }
    for (int i = 0; i < size; i++) {
        delete[] dostizhMatrix[i];
    }
    delete[] dostizhMatrix;
    for (int i = 0; i < size; i++) {
        delete[] graf[i];
    }
    delete[] graf;
    filein.close();
    fileout.close();
    return 0;
}