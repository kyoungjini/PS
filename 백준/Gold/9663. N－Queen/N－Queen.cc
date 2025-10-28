#include <iostream>
#include <cmath>
using namespace std;

int n, res = 0;
int graph[16];

void queen(int cur_row) {

    if (cur_row == n) {
        res++;
        return;
    }

    for (int i = 0; i < n; i++) {
        graph[cur_row] = i;
        bool flag = true;

        for (int j = 0; j < cur_row; j++) {
            if (graph[cur_row] == graph[j] || abs(graph[cur_row] - graph[j]) == cur_row - j) {
                flag = false;
                break;
            } 
        }

        if (flag) queen(cur_row + 1);
    }
}

int main() {
    cin >> n;

    queen(0);

    cout << res << "\n";

    return 0;
}