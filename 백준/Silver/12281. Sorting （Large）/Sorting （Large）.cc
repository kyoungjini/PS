#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        int n;
        vector<bool> isOdd_v;
        priority_queue<int, vector<int>, greater<int>> odd_q;
        priority_queue<int, vector<int>, less<int>> even_q;

        cin >> n;

        for (int j = 0; j < n; j++) {
            int tmp;

            cin >> tmp;

            if (abs(tmp) % 2 == 0) {    // 짝수
                isOdd_v.push_back(false);
                even_q.push(tmp);
            }
            else {                      // 홀수
                isOdd_v.push_back(true);
                odd_q.push(tmp);
            }
        }

        cout << "Case #" << i << ": ";

        for (int j = 0; j < n; j++) {
            if (isOdd_v[j]) {
                cout << odd_q.top() << " ";
                odd_q.pop();
            }
            else {
                cout << even_q.top() << " ";
                even_q.pop();
            }
        }

        cout << "\n";
    }

    return 0;
}