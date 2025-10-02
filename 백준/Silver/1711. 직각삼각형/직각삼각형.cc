#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<pair<long long, long long>> v;
int res = 0;

void triangle(int idx1, int idx2, int idx3) {
    long long x1 = v[idx1].first, y1 = v[idx1].second;
    long long x2 = v[idx2].first, y2 = v[idx2].second;
    long long x3 = v[idx3].first, y3 = v[idx3].second;

    long long isOneLine = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    if (isOneLine == 0) return;

    long long len1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    long long len2 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
    long long len3 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);

    long long max_len = max(len1, max(len2, len3));

    if (max_len == (len1 + len2 + len3 - max_len)) res++;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                triangle(i, j, k);
            }
        }
    }

    cout << res << "\n";

    return 0;
}