#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, res1 = 0, res2 = 0;
    vector<long long> even_v;
    vector<long long> odd_v;

    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        (tmp % 2 == 0) ? even_v.push_back(i) : odd_v.push_back(i);
    }

    // even numbers first
    long long odd_idx = (odd_v.empty() ? 0 : odd_v[0]);
    for (auto even_i: even_v) {
        if (even_i > odd_idx) {
            res1 += (even_i - odd_idx);
            odd_idx++;
        }
    }

    // odd numbers first
    long long even_idx = (even_v.empty() ? 0 : even_v[0]);
    for (auto odd_i: odd_v) {
        if (odd_i > even_idx) {
            res2 += (odd_i - even_idx);
            even_idx++;
        }
    }

    cout << min(res1, res2) << "\n";

    return 0;
}
