#include <iostream>
using namespace std;

int main() {
    double r, s, h, m, d;
    double x, res;

    cin >> r >> s >> h >> m >> d;

    x = s - (h - d) * (s - r) / h;
    res = (m * d * (x * x + x * r + r * r)) / ((h - d) * (s * s + x * s + x * x));

    cout << fixed;
    cout.precision(9);
    cout << res << "\n";

    return 0;
}