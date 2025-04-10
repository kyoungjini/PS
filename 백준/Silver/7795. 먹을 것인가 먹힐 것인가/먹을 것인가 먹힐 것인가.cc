#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        
        int n, m;
        cin >> n >> m;

        vector<int> a;
        vector<int> b;
        int tmp;

        for (int j = 0; j < n; j++) {
            cin >> tmp;
            a.push_back(tmp);
        }
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            b.push_back(tmp);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int res = 0;

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (a[j] > b[k]) res++;
                else break;
            }
        }

        cout << res << "\n";
    }


    return 0;
}