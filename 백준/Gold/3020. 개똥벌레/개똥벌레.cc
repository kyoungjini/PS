#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;

    vector<int> bottom_v(h + 1, 0);
    vector<int> top_v(h + 1, 0);

    for (int i = 0; i < n / 2; i++) {
        int a, b;
        cin >> a >> b;

        bottom_v[a]++;
        top_v[h + 1 - b]++;
    }

    // 석순 누적합
    for (int i = h - 1; i > 0; i--) {
        bottom_v[i] += bottom_v[i + 1];
    }
    
    int min_h = 500000;
    int cnt = 0;

    for (int i = 1; i <= h; i++) {
        // 종유석 누적합
        top_v[i] += top_v[i - 1];

        // 결과 계산
        if (bottom_v[i] + top_v[i] < min_h) {
            min_h = bottom_v[i] + top_v[i];
            cnt = 1;
        }
        else if (bottom_v[i] + top_v[i] == min_h) {
            cnt++;
        }
    }

    cout << min_h << " " << cnt << "\n";

    return 0;
}