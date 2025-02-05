#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define INF 1e9

int n, m;
int res = INF;
bool selected[15];
vector<pair<int, int> > chicken_house_v;
vector<pair<int, int> > house_v;
vector<pair<int, int> > selected_chicken_house_v;

void find_min_chicken_dist() {
    int total_chicken_dist = 0;

    for (int i = 0; i < house_v.size(); i++) {
        int x1 = house_v[i].first;
        int y1 = house_v[i].second;
        int dist;
        int chicken_dist = INF;

        for (int j = 0; j < selected_chicken_house_v.size(); j++) {
            int x2 = selected_chicken_house_v[j].first;
            int y2 = selected_chicken_house_v[j].second;

            dist = abs(x1 - x2) + abs(y1 - y2);
            chicken_dist = min(chicken_dist, dist);
        }

        total_chicken_dist += chicken_dist;
    }

    res = min(res, total_chicken_dist);
}

void select_chicken_house(int idx, int cnt) {

    if (cnt == m) {     // no more chicken house can survive
        find_min_chicken_dist();
        return;
    }

    for (int i = idx; i < chicken_house_v.size(); i++) {
        if (!selected[i]) {
            selected[i] = true;
            selected_chicken_house_v.push_back(make_pair(chicken_house_v[i].first, chicken_house_v[i].second));
            
            select_chicken_house(i + 1, cnt + 1);
            
            selected_chicken_house_v.pop_back();
            selected[i] = false;
        }
    }
}

int main() {
    
    cin >> n >> m;

    // get inputs
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int status;
            cin >> status;

            if (status == 1) house_v.push_back(make_pair(i, j));
            else if (status == 2) chicken_house_v.push_back(make_pair(i, j));
        }
    }

    select_chicken_house(0, 0);

    cout << res << "\n";

    return 0;
}