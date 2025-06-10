#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<string> s;
    int res = 0;

    for (int i = 0; i < n ; i++) {
        string tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    for (int i = 0; i < m; i++) {
        string check;
        cin >> check;
        if (s.find(check) != s.end()) res++;
    }

    cout << res << "\n";

    return 0;
}