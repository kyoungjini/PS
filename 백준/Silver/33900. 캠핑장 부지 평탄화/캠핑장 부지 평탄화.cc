#include <iostream>
#include <set>
using namespace std;

int n, m, r, c;
int graph[1000][1000];
int plan[1000][1000];

bool isPossible(int x, int y) {
    set<int> s;

    for (int i = x; i < x + r; i++) {
        for (int j = y; j < y + c; j++) {
            s.insert(graph[i][j] - plan[i - x][j - y]);
        }
    }

    return s.size() == 1 ? true : false;
}

int main() {
    int res = 0;
    cin >> n >> m >> r >> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m ; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> plan[i][j];
        }
    }

    for (int i = 0; i <= n - r; i++) {
        for (int j = 0; j <= m - c; j++) {
            if (isPossible(i, j)) res++;
        }
    }

    cout << res << "\n";

    return 0;
}