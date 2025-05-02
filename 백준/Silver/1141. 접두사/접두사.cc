#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<string> s;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    int idx = 0;
    string arr[50];
    for (auto iter: s) {
        arr[idx] = iter;
        idx++;
    }

    int res = n;
    for (int i = 0; i < n; i++) {
        string target = arr[i];
        
        for (int j = 0; j < n; j++) {
            if (i == j || arr[j].length() < target.length()) continue;

            if (arr[j].find(target) == 0) {
                res--;
                break;
            } 
        }
    }

    cout << res << "\n";

    return 0;
}