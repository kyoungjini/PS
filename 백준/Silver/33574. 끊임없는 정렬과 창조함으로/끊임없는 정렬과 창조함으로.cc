#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int command, x, t;

        cin >> command;

        if (command == 1) {
            cin >> x;
            if (x == 1) sort(v.begin(), v.end());
            else sort(v.rbegin(), v.rend());
        }
        else {
            cin >> x >> t;
            v.insert(v.begin() + x, t);
        }
    }

    // print the result
    if (v.empty()) return 0;
    
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n";

    return 0;
}