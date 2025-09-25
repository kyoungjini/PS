#include <iostream>
using namespace std;

int street[1000002] = {0, };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int flip_cnt = 0, prev_status = 0;

    for (int i = 1; i <= n; i++) {
        cin >> street[i];
        if (street[i] == 1 && prev_status == 0) flip_cnt++;
        prev_status = street[i];
    }

    int command, idx;
    for (int i = 0; i < m; i++) {
        cin >> command;
        
        if (command == 1) {
            cin >> idx;

            if (street[idx] != 1) {
                street[idx] = 1;

                if (street[idx - 1] == 0 && street[idx + 1] == 0) flip_cnt++;
                else if (street[idx - 1] == 1 && street[idx + 1] == 1) flip_cnt--;
            }
        } else {
            cout << flip_cnt << "\n";
        }
    }

    return 0;
}