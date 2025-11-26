#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 98765432

int n, start_idx, end_idx;
int res = INF;
vector<int> v;
bool visited[10001];

void bfs(int s) {
    queue<pair<int, int>> q;

    q.push({s, 0});

    while (!q.empty()) {
        int cur_idx = q.front().first;
        int cur_cnt = q.front().second;
        q.pop();

        if (cur_idx == end_idx) {
            res = min(res, cur_cnt);
            continue;
        }

        int cur_val = v[cur_idx - 1];
        // jump right
        for (int i = cur_idx - 1 + cur_val; i < n; i += cur_val) {
            if (!visited[i]) {
                visited[i] = true;
                q.push({i + 1, cur_cnt + 1});
            }
        }
        // jump left
        for (int i = cur_idx - 1 - cur_val; i >= 0; i -= cur_val) {
            if (!visited[i]) {
                visited[i] = true;
                q.push({i + 1, cur_cnt + 1});
            }
        }
    }
}

int main() {
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    cin >> start_idx >> end_idx;

    bfs(start_idx);

    cout << (res == INF ? -1 : res) << "\n";

    return 0;
}