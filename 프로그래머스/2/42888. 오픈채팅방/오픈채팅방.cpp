#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> action_v;
    vector<string> uid_v;
    unordered_map<string, string> m;
    
    for (int i = 0; i < record.size(); i++) {
        int first_split = record[i].find(' ');
        string action = record[i].substr(0, first_split);
        action_v.push_back(action);
        
        string uid;
        if (action == "Leave") {
            uid = record[i].substr(first_split + 1);
        } else {
            int second_split = record[i].find(' ', first_split + 1);
            uid = record[i].substr(first_split + 1, second_split - first_split - 1);
            string nickname = record[i].substr(second_split + 1);
            m[uid] = nickname;
            
        }
        uid_v.push_back(uid);
    }
    
    for (int i = 0; i < action_v.size(); i++) {
        string cur_uid = uid_v[i];
        string cur_action = action_v[i];
        
        if (cur_action == "Leave") {
            answer.push_back(m[cur_uid] + "님이 나갔습니다.");
        } else if (cur_action == "Enter") {
            answer.push_back(m[cur_uid] + "님이 들어왔습니다.");
        }
    }
    
    return answer;
}