#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool graph[101][101] = {false};
bool visited[101] = {false};
int cnt = 0;

void dfs(int n, int x) {
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && graph[x][i]) {
            visited[i] = true;
            cnt++;
            dfs(n, i);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    for (int i = 0; i < wires.size(); i++) {
        int a = wires[i][0], b = wires[i][1];
        graph[a][b] = true;
        graph[b][a] = true;
    }
    
    for (int i = 0; i < wires.size(); i++) {
        int a = wires[i][0], b = wires[i][1];
        fill(visited, visited + 101, false);
        cnt = 0;
        
        graph[a][b] = false;
        graph[b][a] = false;
        
        dfs(n, 1);
        int connected_nodes = cnt;
        int diff = abs(n - connected_nodes - connected_nodes);
        answer = min(answer, diff);

        graph[a][b] = true;
        graph[b][a] = true;
    }
    
    return answer;
}