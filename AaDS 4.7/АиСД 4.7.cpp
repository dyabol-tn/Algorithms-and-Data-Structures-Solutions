#include <iostream>
#include <fstream>
#include <queue>
#include <climits>

using namespace std;

int main() {
    ifstream filein("input.txt");
    ofstream fileout("output.txt");
    int vershCount, rebrCount;
    filein >> vershCount >> rebrCount;
    if (vershCount == 1) {
        fileout << "0";
        return 0;
    }
    int* goal = new int[2 * rebrCount];
    int* weight = new int[2 * rebrCount];
    int* sled = new int[2 * rebrCount];
    int* first = new int[vershCount + 1];
    for (int i = 1; i <= vershCount; i++) {
        first[i] = -1;
    }
    int rebrCounter = 0;
    for (int i = 0; i < rebrCount; i++) {
        int u, v, w;
        filein >> u >> v >> w;
        goal[rebrCounter] = v;
        weight[rebrCounter] = w;
        sled[rebrCounter] = first[u];
        first[u] = rebrCounter;
        rebrCounter++;
        if (u != v) {
            goal[rebrCounter] = u;
            weight[rebrCounter] = w;
            sled[rebrCounter] = first[v];
            first[v] = rebrCounter;
            rebrCounter++;
        }
    }
    long long* dist = new long long[vershCount + 1];
    for (int i = 1; i <= vershCount; i++) {
        dist[i] = LLONG_MAX;
    }
    dist[1] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({ 0, 1 });
    while (!pq.empty()) {
        long long currentDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (currentDist > dist[u]) {
            continue;
        }
        if (u == vershCount) {
            fileout << currentDist;
            delete[] goal;
            delete[] weight;
            delete[] sled;
            delete[] first;
            delete[] dist;
            return 0;
        }
        int rebrIndex = first[u];
        while (rebrIndex != -1) {
            int v = goal[rebrIndex];
            int w = weight[rebrIndex];
            long long newDist = currentDist + w;
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({ newDist, v });
            }
            rebrIndex = sled[rebrIndex];
        }
    }
    fileout << dist[vershCount];
    delete[] goal;
    delete[] weight;
    delete[] sled;
    delete[] first;
    delete[] dist;
    filein.close();
    fileout.close();
    return 0;
}