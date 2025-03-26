#include <iostream>
#include <map>
using namespace std;

int main() {
    long long b;
    int n, m;
    cin >> b >> n >> m;

    map<string, long long> item_list;

    for (int i = 0; i < n; i++) {
        string s;
        long long p;
        cin >> s >> p;

        item_list.insert({s, p});
    }

    long long wish = 0;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        wish += item_list[s];
    }

    cout << (wish > b ? "unacceptable" : "acceptable") << "\n";

    return 0;
}