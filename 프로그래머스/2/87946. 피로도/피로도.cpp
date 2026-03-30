#include <string>
#include <vector>

using namespace std;

int answer = -1;
bool visited[8];

void dfs(vector<vector<int>> &dungeons, int left_blood, int dungeon_cnt) {
    answer = max(answer, dungeon_cnt);
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (visited[i] || left_blood < dungeons[i][0]) continue;
        
        visited[i] = true;
        dfs(dungeons, left_blood - dungeons[i][1], dungeon_cnt + 1);
        visited[i] = false;
    }
    
}

int solution(int k, vector<vector<int>> dungeons) {
    for (int i = 0; i < dungeons.size(); i++) {
        if (k < dungeons[i][0]) continue;
        
        visited[i] = true;
        dfs(dungeons, k - dungeons[i][1], 1);
        visited[i] = false;
    }

    return answer;
}