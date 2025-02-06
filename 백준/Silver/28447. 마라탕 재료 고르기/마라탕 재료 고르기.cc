// 마라탕 재료 고르기
#include <iostream>
#include <vector>
using namespace std;

int n, k;
int res = -1e9;
int arr[11][11] = {0,};
bool visited[11];
vector<int> v;

void flavor() {
    int total_flavor = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (visited[i] && visited[j]) {
                total_flavor += arr[i][j];
            }
        }
    }

    res = max(res, total_flavor);
}

void combination(int idx, int cnt) {

    if (cnt == k) {
        flavor();
        return;
    }

    for (int i = idx; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            combination(i + 1, cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    if (k == 1) cout << 0 << "\n";
    else {
        combination(0, 0);
        cout << res << "\n";
    }

    return 0;
}