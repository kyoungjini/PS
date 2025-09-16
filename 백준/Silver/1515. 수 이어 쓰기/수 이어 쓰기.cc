#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string s;
    cin >> s;

    int res = 1;
    int idx = 0;

    while (idx < s.length()) {
        string res_str = to_string(res);

        for (auto c: res_str) {
            if (c == s[idx]) idx++;
        }

        res++;
    }

    cout << res - 1 << "\n";

    return 0;
}