#include <vector>
#include <queue>
using namespace std;

// up down left right
int x_dir[4] = {-1, 1, 0, 0};
int y_dir[4] = {0, 0, -1, 1};
bool visited[101][101] = {false};
int answer = -1;

void bfs(vector<vector<int>> &maps, int start_x, int start_y) {
    queue<vector<int>> q;
    
    q.push({start_x, start_y, 1});
    
    while (!q.empty()) {
        vector<int> v = q.front();
        int x = v[0], y = v[1], cnt = v[2];
        q.pop();
        
        if (x == maps.size() - 1 && y == maps[0].size() - 1) {
            answer = cnt;
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            int next_x = x + x_dir[i];
            int next_y = y + y_dir[i];
            
            if (next_x < 0 || next_x >= maps.size() || next_y < 0 || next_y >= maps[0].size()) continue;
            
            if (!visited[next_x][next_y] && maps[next_x][next_y]) {
                visited[next_x][next_y] = true;
                q.push({next_x, next_y, cnt + 1});
            }
        }
    }
}

int solution(vector<vector<int>> maps)
{   
    bfs(maps, 0, 0);
    
    return answer;
}