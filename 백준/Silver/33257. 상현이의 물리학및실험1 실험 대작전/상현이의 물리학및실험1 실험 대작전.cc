#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int> v;

    // get inputs
    int n, e;
    cin >> n >> e;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    // sort
    sort(v.begin(), v.end());

    // result
    int res = 0;

    for(int i = 0; i < n; i++) {
        if(i == 0) res++;
        else {
            if(v[i] - v[i - 1] >= e) res++;
        }
    }

    cout << res << "\n";

    return 0;
}