#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void PushSteps(int minSteps[101][101], pair<int, int>* q, int f, int s, int st, int& tail) {
    if (f < 0 || s < 0 || f + s > 100 || minSteps[f][s] != -1) {
        return;
    }
    minSteps[f][s] = st;
    q[tail++] = { f, s };
}

int main() {
    ifstream filein("in.txt");
    ofstream fileout("out.txt");
    int fir, sec, x;
    filein >> x >> fir >> sec;

    vector<int> delims;
    int temp;
    while (filein >> temp) {
        delims.push_back(temp);
    }
    delims.push_back(100);
    sort(delims.begin(), delims.end());
    int minSteps[101][101];
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            minSteps[i][j] = -1;
        }
    }
    pair<int, int> q[10201];
    int head = 0, tail = 0;
    PushSteps(minSteps, q, fir, sec, 0, tail);
    while (head < tail) {
        int firNow = q[head].first;
        int secNow = q[head].second;
        head++;
        int third = 100 - firNow - secNow;
        if (third == x) {
            fileout << minSteps[firNow][secNow];
            return 0;
        }
        int prob[3] = { firNow, secNow, third };
        for (int i = 0; i < 3; i++) {
            if (prob[i] == 0) continue;
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                int haveLitr = prob[j];
                int freeLitr = 100 - haveLitr;
                if (freeLitr == 0) continue;
                if (j != 2) {
                    for (int k = 0; k < delims.size(); k++) {
                        int target = delims[k];
                        if (target <= haveLitr) continue;
                        int vol = target - prob[j];
                        if (vol <= prob[i] && vol <= freeLitr) {
                            int newSost[3] = { prob[0], prob[1], prob[2] };
                            newSost[i] -= vol;
                            newSost[j] += vol;
                            PushSteps(minSteps, q, newSost[0], newSost[1], minSteps[firNow][secNow] + 1, tail);
                        }
                    }
                }
                if (i != 2) {
                    for (int k = 0; k < delims.size(); k++) {
                        int target = delims[k];
                        if (target >= prob[i]) continue;
                        int vol = prob[i] - target;
                        if (vol <= freeLitr) {
                            int newSost[3] = { prob[0], prob[1], prob[2] };
                            newSost[i] -= vol;
                            newSost[j] += vol;
                            PushSteps(minSteps, q, newSost[0], newSost[1], minSteps[firNow][secNow] + 1, tail);
                        }
                    }
                }

                int vol = min(freeLitr, prob[i]);
                if (vol > 0) {
                    int newSost[3] = { prob[0], prob[1], prob[2] };
                    newSost[i] -= vol;
                    newSost[j] += vol;
                    PushSteps(minSteps, q, newSost[0], newSost[1], minSteps[firNow][secNow] + 1, tail);
                }
            }
        }
    }
    fileout << "No solution";
    filein.close();
    fileout.close();
    return 0;
}