#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long res1 = 0, res2 = 0, res3 = 0;
    vector<long long> v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        v.push_back(tmp);
        res1 += tmp;
    }
    
    // 오름차순 정렬
    sort(v.begin(), v.end());

    // two positive numbers
    long long first_max_val = v[v.size() - 1];
    long long second_max_val = v[v.size() - 2];

    if (first_max_val > 0 && second_max_val > 0) {
        res2 = res1 - (first_max_val + second_max_val);
        res2 += 2 * first_max_val * second_max_val;
    }

    // two negative numbers
    long long first_min_val = v[0];
    long long second_min_val = v[1];

    if (first_min_val <= 0 && second_min_val <= 0) {
        res3 = res1 - (first_min_val + second_min_val);
        res3 += 2 * first_min_val * second_min_val;
    }

    cout << max(res1, max(res2, res3)) << "\n";

    return 0;
}