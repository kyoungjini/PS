#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<long long> v;

void brute_force(int target) {
    queue<long long> q;

    // initialize
    for (long long i = 0; i < 10; i++) {
        q.push(i);
        v.push_back(i);
    }

    while (!q.empty()) {
        long long cur_num = q.front();
        q.pop();

        for (long long i = 0; i < cur_num % 10; i++) {
            long long next_num = cur_num * 10 + i;
            q.push(next_num);
            v.push_back(next_num);
        }
    }
}

int main() {
    int n;
    cin >> n;

    brute_force(n);

    cout << (n >= v.size() ? -1 : v[n]) << "\n";

    return 0;
}