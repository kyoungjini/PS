#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;;

int main() {

    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(a);
        v.push_back(b);
    }

    sort(v.begin(), v.end());
   
    int res = 200000;

    for (int i = 0; i < n; i++) {
        res = min(res, v[i] + v[2 * n - i - 1]);
    }

    cout << res << "\n";

    return 0;
}