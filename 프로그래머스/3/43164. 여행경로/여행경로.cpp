#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> ticket;
vector<string> answer;
bool visited[100000] = {false};
bool flag = false;

void dfs(string target, int cnt) {
    answer.push_back(target);
    
    if (cnt == ticket.size()) flag = true;
    
    for (int i = 0; i < ticket.size(); i++) {
        if (!visited[i] && ticket[i][0] == target) {
            visited[i] = true;
            dfs(ticket[i][1], cnt + 1);
            
            if (!flag) {
                answer.pop_back();
                visited[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    ticket = tickets;    
    sort(ticket.begin(), ticket.end());

    dfs("ICN", 0);
    
    return answer;
}