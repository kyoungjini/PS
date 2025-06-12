#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    if (s[0] != 'A' || s[n - 1] != 'B') cout << "No\n";
    else cout << "Yes\n";

    return 0;
}