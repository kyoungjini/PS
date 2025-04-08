#include <iostream>
using namespace std;

int main() {
    long long s;
    cin >> s;

    long long res = 1e10;
    long long start = 1;
    long long end = s;
    bool flag = false;

    while (start <= end) {
        long long mid = (start + end) / 2;
        long long tmp = mid * (mid + 1) / 2;

        if (tmp < s) start = mid + 1;
        else if (tmp == s) {
            res = mid;
            flag = true;
            break;
        }
        else {
            res = min(res, mid);
            end = mid - 1;
        }
    }

    cout << (flag ? res : res - 1) << "\n";

    return 0;
}