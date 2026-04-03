#include <string>
#include <vector>

using namespace std;

bool graph[101][101] = {false};

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for (int i = 0; i < results.size(); i++) {
        int winner = results[i][0];
        int loser = results[i][1];
        
        graph[winner][loser] = true;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] && graph[k][j]) graph[i][j] = true;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int win_cnt = 0, lose_cnt = 0;
        
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            
            if (graph[i][j]) win_cnt++;
            else if (graph[j][i]) lose_cnt++;
        }
        
        if ((win_cnt + lose_cnt) == n - 1) answer++;
    }
    
    return answer;
}