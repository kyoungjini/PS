#include <iostream>
#include <stack>
using namespace std;

int input[1000001];
int f[1000001];
int res[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    stack<pair<int, int>> s;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        f[input[i]]++;
    }

    for (int i = 0; i < n; i++) {
        while(!s.empty()) {
            if (f[s.top().first] < f[input[i]]) {
                res[s.top().second] = input[i];
                s.pop();
            } else {
                break;
            }
        }

        s.push({input[i], i});
    }

    for (int i = 0; i < n; i++) {
        cout << (res[i] == 0 ? -1 : res[i]) << " ";
    }
    cout << "\n";
    
    return 0;
}