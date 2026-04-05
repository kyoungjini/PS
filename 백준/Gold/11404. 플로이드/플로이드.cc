#include <iostream>

using namespace std;

int graph[101][101] = {0};

int main() {
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int city1, city2, cost;
        cin >> city1 >> city2 >> cost;

        if (graph[city1][city2] == 0) graph[city1][city2] = cost;
        else graph[city1][city2] = min(graph[city1][city2], cost);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i == k) continue;
            for (int j = 1; j <= n; j++) {
                if (j == i || j == k) continue;
                if (graph[i][k] > 0 && graph[k][j] > 0) {
                    if (graph[i][j] == 0) graph[i][j] = graph[i][k] + graph[k][j];
                    else graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}