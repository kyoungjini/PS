#include <iostream>
using namespace std;

int n, m, x;
int height[100001];

int main() {
    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        cin >> height[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char cur = '.';
            
            if (n - i == x) {
                if (n - i <= height[j]) cur = '*';
                else cur = '-';
                cout << cur;
                continue;
            }

            if (n - i <= height[j]) {            // mountain
                cur = '#';
            } else {                            // not mountain
                if (n - i < x && (j + 1) % 3 == 0) cur = '|';
            }

            cout << cur;
        }
        cout << "\n";
    }

    return 0;
}