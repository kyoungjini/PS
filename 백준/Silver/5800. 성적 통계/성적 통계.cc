#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int k;
    cin >> k;

    for (int i = 1; i <= k; i++) {
        int n;
        cin >> n;

        vector<int> v;

        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }

        sort(v.begin(), v.end());

        int max_gap = 0;

        for (int j = 0; j < n - 1; j++) {
            max_gap = max(max_gap, v[j + 1] - v[j]);
        }

        cout << "Class " << i << "\n";
        printf("Max %d, Min %d, Largest gap %d\n", v[n - 1], v[0], max_gap);
    }

    return 0;
}