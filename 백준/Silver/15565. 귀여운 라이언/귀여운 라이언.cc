#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int info;
        cin >> info;

        if (info == 1) v.push_back(i);
    }

    // impossible case
    if (v.size() < k) {
        cout << "-1\n";
        return 0;
    }

    // possible case
    int s = 0;
    int e = k - 1;
    int res = 1e9;

    while (true) {
        if (e > v.size() - 1) break;

        if (v[e] - v[s] + 1 < res) res = v[e] - v[s] + 1;

        s++;
        e++;
    }

    cout << res << "\n";

    return 0;
}