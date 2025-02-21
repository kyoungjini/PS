#include <iostream>
using namespace std;

int divide_n(int n) {

    int res;
    int cnt = 0;

    // 입력으로 한자리 수가 주어질 때
    if (0 < n && n < 10) {
        res = 1;
        return res;
    }

    while (true) {

        bool flag = false;

        for (int i = 9; i > 1; i--) {
            if (n % i == 0) {
                n /= i;
                cnt++;
                flag = true;
                break;
            }
        }

        if (flag && 1 < n && n < 10) {
            res = cnt + 1;
            break;
        }

        if (!flag) {
            res = -1;
            break;
        }
    }

    return res;
}

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        int res = divide_n(n);

        cout << res << "\n";
    }

    return 0;
}