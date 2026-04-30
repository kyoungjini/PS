#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF (int)1e9
vector<pair<int, int>> graph[51];
int dist[51];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int cur_cost = pq.top().first;
        int cur_idx = pq.top().second;
        pq.pop();
        
        if (dist[cur_idx] < cur_cost) continue;
        
        for (int i = 0; i < graph[cur_idx].size(); i++) {
            int next_cost = graph[cur_idx][i].second + cur_cost;
            int next_idx = graph[cur_idx][i].first;
            
            if (next_cost < dist[next_idx]) {
                dist[next_idx] = next_cost;
                pq.push({next_cost, next_idx});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    // make a graph
    for (int i = 0; i < road.size(); i++) {
        graph[road[i][0]].push_back({road[i][1], road[i][2]});
        graph[road[i][1]].push_back({road[i][0], road[i][2]});
    }
    
    // initialize dist
    for (int i = 0; i <= N; i++) dist[i] = INF;
    
    dijkstra(1);
    
    // result
    for (int i = 1; i <= N; i++) {
        if (dist[i] <= K) answer++;
    }

    return answer;
}