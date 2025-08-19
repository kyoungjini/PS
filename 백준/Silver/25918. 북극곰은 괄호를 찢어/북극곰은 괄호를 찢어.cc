#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    int level = 0, res = 0;
    stack<char> s;

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        if (s.empty()) {
            s.push(c);
            level = 1;
        } else {
            if (s.top() == c) {
                s.push(c);
                level++;
            } else {
                s.pop();
                level--;
            }
        }

        res = max(res, level);
    }

    cout << (s.empty() ? res : -1) << "\n";

    return 0;
}