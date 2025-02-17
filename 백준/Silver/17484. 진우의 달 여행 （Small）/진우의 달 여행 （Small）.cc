#include <iostream>
using namespace std;

int n, m;
int min_total_fuel = 2000;
int arr[7][7];
int y_dir[3] = {-1, 0, 1};  // 1=서남쪽, 2=남쪽, 3=동남쪽

void dfs (int x, int y, int fuel, int dir) {

    if (x == n - 1) {
        min_total_fuel = min(min_total_fuel, fuel);
        return;
    }

    for (int i = 0; i < 3; i++) {
        int next_x = x + 1;
        int next_y = y + y_dir[i];

        if (0 <= next_y && next_y < m && dir != i + 1) {
            dfs(next_x, next_y, fuel + arr[next_x][next_y], i + 1);
        }
    }
}

int main() {
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m ; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < m; i++) {
        dfs(0, i, arr[0][i], 0);
    }

    cout << min_total_fuel << "\n";

    return 0;
}