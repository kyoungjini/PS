#include <iostream>
#include <cmath>
using namespace std;

bool line[900000];

void remove_line(int offset, int n) {
    int x = pow(3, n - 1);

    for (int i = offset + x; i < offset + 2 * x; i++) line[i] = false;

    if (n == 1) return;

    remove_line(offset, n - 1);
    remove_line(offset + 2 * x, n - 1);
}

int main() {
    int n;

    while (true) {
        cin >> n;
        if (cin.eof()) break;

        int x = pow(3, n);
        fill(line, line + x, true);
        if (n > 0) remove_line(0, n);

        for (int i = 0; i < x; i++) cout << (line[i] ? "-" : " ");
        cout << "\n";
    }

    return 0;
}