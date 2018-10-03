#include <iostream>
#include <vector>

using namespace std;

int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    int M = 1000000;
    vector<vector<int> > g(N, vector<int> (N, M));
    vector<int> dist(N, M);
    vector<bool> visit(N, false);
    for (int i = 0; i < times.size(); i++) {
        g[times[i][0] - 1][times[i][1] - 1] = times[i][2];
    }
    dist[K - 1] = 0;
    for (int i = 0; i < N; i++) {
        int dmin = M, posmin = -1;
        for (int j = 0; j < N; j++) {
            if (!visit[j] && dist[j] < dmin) {
                dmin = dist[j];
                posmin = j;
            }
        }
        if (posmin != -1) visit[posmin] = true;
        else return -1;
        for (int j = 0; j < N; j++) {
            if (!visit[j] && dist[posmin] + g[posmin][j] < dist[j]) {
                dist[j] = dist[posmin] + g[posmin][j];
            }
        }
    }
    int maxdist = 0;
    for (int i = 0; i < N; i++) {
        cout << dist[i] << endl;
        if (dist[i] > maxdist) maxdist = dist[i];
    }
    if (maxdist >= M) return -1;
    return maxdist;
}
