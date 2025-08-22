#include <iostream>
using namespace std;

int arr[200001][28] = {0, };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    int q;
    
    cin >> s >> q;
    
    for (int i = 0; i < s.length(); i++) {
        char cur_c = s[i];

        for (int j = 0; j < 26; j++) {
            if (cur_c - 'a' == j) arr[i + 1][j] = arr[i][j] + 1;
            else arr[i + 1][j] = arr[i][j];
        }
    }

    char c;
    int l, r;
    
    for (int i = 0; i < q; i++) {
        cin >> c >> l >> r;
        cout << arr[r + 1][c - 'a'] - arr[l][c - 'a'] << "\n";
    }

    return 0;
}