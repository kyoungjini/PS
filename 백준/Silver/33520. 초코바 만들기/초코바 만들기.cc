#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long tmp, res_w = 0, res_h = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;

        if (a > b) {
            tmp = a;
            a = b;
            b = tmp;
        }

        res_w = max(res_w, a);
        res_h = max(res_h, b);
    }

    cout << res_w * res_h << "\n";

    return 0;
}