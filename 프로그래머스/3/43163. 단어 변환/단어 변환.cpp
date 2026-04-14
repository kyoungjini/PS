#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string, int>> q;
    bool visited[51] = {false};
    
    q.push({begin, 0});
    
    while (!q.empty()) {
        string s = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if (s == target) {
            answer = cnt;
            break;
        }
        
        for (int i = 0; i < words.size(); i++) {
            if (visited[i]) continue;
            
            string word = words[i];
            int diff_s_t = 0, diff_s_w = 0, diff_w_t = 0;
            
            for (int j = 0; j < word.length(); j++) {
                if (s[j] != target[j]) diff_s_t++;
                if (s[j] != word[j]) diff_s_w++;
                if (word[j] != target[j]) diff_w_t++;
            }
            
            if (diff_s_w == 1 && (diff_s_t >= diff_w_t)) {
                visited[i] = true;
                q.push({word, cnt + 1});
            }
        }
    }
    
    return answer;
}