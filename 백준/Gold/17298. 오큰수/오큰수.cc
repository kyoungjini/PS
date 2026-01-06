#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int res[1000001] = {0, };
    stack<pair<int, int>> s;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        
        if (i == 0) {
            s.push({tmp, i});
            continue;
        }

        while (!s.empty()) {
            if (s.top().first < tmp) {
                res[s.top().second] = tmp;
                s.pop();
            } else {
                break;
            }
        }
        
        s.push({tmp, i});
    }

    for (int i = 0; i < n; i++) {
        cout << (res[i] == 0 ? -1 : res[i]) << " ";
    }
    cout << "\n";

    return 0;
}