#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void hanoi(int n, int start, int end, int tmp) {
    if (n == 1) {
        cout << start << " " << end << "\n";
        return;
    }

    hanoi(n - 1, start, tmp, end);
    cout << start << " " << end << "\n";
    hanoi(n - 1, tmp, end, start);
}

int main() {
    int n;
    cin >> n;

    // 옮긴 횟수 출력
    string res = to_string(pow(2, n));
    int dot_idx = res.find('.');

    res = res.substr(0, dot_idx);
    res[res.length() - 1] -= 1;

    cout << res << "\n";

    // 이동 과정 출력
    if (n <= 20) hanoi(n, 1, 3, 2);

    return 0;
}