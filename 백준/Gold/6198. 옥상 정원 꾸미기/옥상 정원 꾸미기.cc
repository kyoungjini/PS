#include <iostream>
#include <stack>
using namespace std;

int n;
long long res = 0;
stack<long long> h;

void calc(long long x) {
    while (!h.empty()) {
        if (h.top() <= x) h.pop();
        else break;
    }

    res += h.size();
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        if (!h.empty()) calc(tmp);
        h.push(tmp);
    }

    cout << res << "\n";

    return 0;
}