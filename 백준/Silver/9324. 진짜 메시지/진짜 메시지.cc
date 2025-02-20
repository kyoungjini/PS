#include <iostream>
using namespace std;

bool isFake(string s) {

    int arr[28] = {0, };

    for (int i = 0; i < s.length(); i++) {

        int cur_idx = s[i] - 65;

        arr[cur_idx]++;

        if (arr[cur_idx] == 3) {
            if (i + 1 < s.length() && s[i] == s[i + 1]) {
                arr[cur_idx] = 0;
                i++;
            }
            else {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;

        bool flag = isFake(s);

        if (flag) cout << "FAKE\n";
        else cout << "OK\n";
    }

    return 0;
}