#include <iostream>
using namespace std;

int main() {
    int n, min_cnt;
    int one_cnt = 0, two_cnt = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        input == 1 ? one_cnt++ : two_cnt++;
    }

    min_cnt = min(one_cnt, two_cnt);
    one_cnt -= min_cnt;
    two_cnt -= min_cnt;

    cout << ((one_cnt % 3 == 0) && (two_cnt == 0) ? "Yes" : "No") << "\n";

    return 0;
}