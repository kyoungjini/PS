#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[501][501] = {0, };
int arr_size = 0;

void slice_string(string s) {
    queue<int> tmp;
    int s_idx = 0, e_idx = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{') {
            s_idx = i + 1;
        } else if (s[i] == '}') {
            if (s[i - 1] != '}') {
                e_idx = i;
                tmp.push(stoi(s.substr(s_idx, e_idx - s_idx)));
            } else {
                int cnt = tmp.size();
                arr_size = max(arr_size, cnt);
                for (int j = 0; j < cnt; j++) {
                    arr[cnt][j] = tmp.front();
                    tmp.pop();
                }
            }
        } else if (s[i] == ',') {
            if (s[i - 1] == '}') {
                int cnt = tmp.size();
                arr_size = max(arr_size, cnt);
                for (int j = 0; j < cnt; j++) {
                    arr[cnt][j] = tmp.front();
                    tmp.pop();
                }
            } else {
                e_idx = i;
                tmp.push(stoi(s.substr(s_idx, e_idx - s_idx)));
                s_idx = i + 1;
            }
        }
    }
}

vector<int> solution(string s) {
    vector<int> answer;
    
    slice_string(s);
    
    for (int i = 1; i <= arr_size; i++) {
        for (int j = 0; j < i; j++) {
            if (answer.empty() || find(answer.begin(), answer.end(), arr[i][j]) == answer.end()) {
                answer.push_back(arr[i][j]);
            }
        }
    }
    
    return answer;
}