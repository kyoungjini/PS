#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;
    int time = 0;
    vector<int> v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    while (true) {
        if (v.empty()) break;

        if (v.size() == 1) {
            time += v[0];
            break;
        }

        sort(v.rbegin(), v.rend());

        v[0]--;
        v[1]--;
        time++;

        if (v[0] == 0 && v[1] != 0) {
            v.erase(v.begin());
        }
        else if (v[0] == 0 && v[1] == 0) {
            v.erase(v.begin());
            v.erase(v.begin());
        }
        else if (v[1] == 0) {
            v.erase(v.begin() + 1);
        }

    }

    if (time > 1440) time = -1;
    cout << time << "\n";

    return 0;
}