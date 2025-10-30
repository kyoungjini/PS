#include <iostream>
#include <vector>
using namespace std;

long long n, b;
long long mat[6][6];
long long tmp[6][6];
long long ans[6][6];

void mat_multiply(long long x[6][6], long long y[6][6]) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = 0;
            for (int k = 0; k < n; k++) {
                tmp[i][j] += x[i][k] * y[k][j];
            }
            
            tmp[i][j] %= 1000;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x[i][j] = tmp[i][j];
        }
    }
}

int main() {
    cin >> n >> b;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
        ans[i][i] = 1;
    }

    while (b > 0) {
        if (b % 2 != 0) mat_multiply(ans, mat);
        mat_multiply(mat, mat);
        b /= 2;
    }

    // print result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}