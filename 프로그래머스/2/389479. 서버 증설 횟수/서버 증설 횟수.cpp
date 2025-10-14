#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int server[24] = {0, };
    
    for (int i = 0; i < 24; i++) {
        int need = players[i] / m;
        
        if (server[i] >= need) continue;
        
        int add_server = need - server[i];
        answer += add_server;
        
        for (int j = 0; j < k; j++) {
            if (i + j > 23) break;
            server[i + j] += add_server;
        }
    }
    
    return answer;
}