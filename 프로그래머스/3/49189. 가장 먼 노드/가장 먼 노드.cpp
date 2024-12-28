#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int graph[20001][20001];
bool visited[20001];

int bfs(int n, int s_node, int s_level) {
    queue<pair<int, int>> q;
    int max_level = 0;
    int res = 0;
    
    visited[s_node] = true;
    q.push({s_node, s_level});
    
    while(!q.empty()) {
        int node = q.front().first;
        int level = q.front().second;
        q.pop();
        
        for(int i = 1; i <= n; i++) {
            if(!visited[i] && graph[node][i] == 1) {
                if (level + 1 == max_level) res++;
                else if (level + 1 > max_level) {
                    max_level = level + 1;
                    res = 1;
                }
                
                visited[i] = true;
                q.push({i, level + 1});
            }
        }
    }
    
    return res;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    // save graph info
    for(int i = 0; i < edge.size(); i++) {
        int a_node = edge[i][0];
        int b_node = edge[i][1];
       
        graph[a_node][b_node] = 1;
        graph[b_node][a_node] = 1;
    }
    
    answer = bfs(n, 1, 0);
    
    return answer;
}