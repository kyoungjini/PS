#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> m;
    vector<string> v;

    for (int i = 0; i < n; i++) {
        string name, record;
        cin >> name >> record;

        if (record == "enter") {
            if (m.find(name) != m.end()) m[name] = 1;  // 맵에 이미 존재
            else m.insert({name, 1});
        }
        else m[name] = 0;
    }

    for (auto iter: m) {
        if (iter.second) v.push_back(iter.first);
    }

    sort(v.rbegin(), v.rend());

    for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";

    return 0;
}