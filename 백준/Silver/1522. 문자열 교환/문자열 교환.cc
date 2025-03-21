#include <iostream>
using namespace std;

int main() {

    string s;
    cin >> s;

    int a_cnt = 0;
    int res = 1000;

    for (auto c : s) {
        if (c == 'a') a_cnt++;
    }

    for (int i = 0; i < s.size(); i++) {
        int left_a_cnt = a_cnt;
        int change_cnt = 0;

        for (int j = i; j < i + s.size(); j++) {
            if (left_a_cnt == 0) break;

            if (s[j % s.size()] == 'b') change_cnt++;
            
            left_a_cnt--;
        }

        res = min(res, change_cnt);
    }

    cout << res << "\n";

    return 0;
}