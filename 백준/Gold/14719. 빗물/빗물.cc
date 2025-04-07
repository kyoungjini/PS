#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    // get inputs
    vector<int> v;
    for (int i = 0; i < w; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int res = 0;

    // 층별 계산
    for (int i = 1; i <= h; i++) {
        int cnt = 0;
        int prev_idx = 0;

        for (int j = 0; j < w; j++) {
            if (v[j] >= i && prev_idx == 0) {
                prev_idx = j + 1;
            }
            else if (v[j] >= i) {
                cnt += j - prev_idx;
                prev_idx = j + 1;
            }
        }

        res += cnt;
    }

    cout << res << "\n";

    return 0;
}