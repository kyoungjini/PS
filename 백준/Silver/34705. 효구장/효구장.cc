#include <iostream>
using namespace std;

long long x, y;
long long arr[5];
bool flag;

void back_tracking(int idx, long long w) {

    if (x <= w && w <= y) {
        flag = true;
        return;
    } else if (w > y) {
        return;
    }

    for (int i = idx; i < 5; i++) {
        if (!flag) {
            back_tracking(i + 1, w + arr[i]);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> x >> y;
        cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];

        flag = false;
        back_tracking(0, 0);

        cout << (flag ? "YES" : "NO") << "\n";
    }

    return 0;
}