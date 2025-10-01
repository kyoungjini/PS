#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> res;

void search(int start_idx, int cnt) {
    if (cnt <= 0) return;

    res.push_back(v[start_idx]);

    if (cnt == 1) return;

    int left_tree_cnt = 0, left_tree_idx = 0, right_tree_idx = 0;

    for (int i = start_idx + 1; i < start_idx + cnt; i++) {
        if (v[start_idx] < v[i]) {
            right_tree_idx = i;
            break;
        }

        if (left_tree_cnt == 0)  left_tree_idx = i;
        left_tree_cnt++;
    }

    search(right_tree_idx, cnt - left_tree_cnt - 1);
    search(left_tree_idx, left_tree_cnt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int node;

    while (cin >> node) {
        v.push_back(node);
    }

    search(0, v.size());

    for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << "\n";

    return 0;
}