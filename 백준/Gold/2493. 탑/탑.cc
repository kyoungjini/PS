#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    vector<pair<int, int>> v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int res = -1;
        int new_tower;
        
        cin >> new_tower;
        v.push_back({new_tower, i});

        for (int j = v.size() - 2; j >= 0; j--) {
            if (v[j].first < new_tower) {
                v.erase(v.begin() + j);
            } else {
                res = v[j].second + 1;
                break;
            }
        }

        cout << (res == -1 ? 0 : res) << " "; 
    }

    cout << "\n";

    return 0;
}