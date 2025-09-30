#include <iostream>
using namespace std;

#define MAX 6200
int graph[MAX][MAX];

void star(int x, int y, int n) {

    if (n == 3) {
        graph[x][y] = 1;
        graph[x + 1][y - 1] = 1;
        graph[x + 1][y + 1] = 1;
        graph[x + 2][y - 2] = 1;
        graph[x + 2][y - 1] = 1;
        graph[x + 2][y] = 1;
        graph[x + 2][y + 1] = 1;
        graph[x + 2][y + 2] = 1;
    } else {
        n /= 2;
        star(x, y, n);
        star(x + n, y - n, n);
        star(x + n, y + n, n);
    }
}

int main() {
    int n;
    cin >> n;

    star(0, n - 1, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            cout << (graph[i][j] ? '*' : ' ');
        }
        cout << "\n";
    }

    return 0;
}