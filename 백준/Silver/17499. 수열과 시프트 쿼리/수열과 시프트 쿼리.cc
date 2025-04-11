#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int start_idx = 0;

    for (int i = 0; i < q; i++) {
        int command;
        cin >> command;

        int idx, x;

        if (command == 1) {
            cin >> idx >> x;
            v[(start_idx + idx - 1) % n] += x;
        }
        else if (command == 2) {
            cin >> x;
            start_idx = (start_idx + n - x) % n;
        }
        else if (command == 3) {
            cin >> x;
            start_idx = (start_idx + x) % n;
        }
    }

    for (int i = start_idx; i < start_idx + n; i++) cout << v[i % n] << " ";
    cout << "\n";

    return 0;
}