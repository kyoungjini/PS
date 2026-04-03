#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int video_len_num = stoi(video_len.substr(0, 2)) * 60 + stoi(video_len.substr(3, 2));
    int pos_num = stoi(pos.substr(0, 2)) * 60 + stoi(pos.substr(3, 2));
    int op_start_num = stoi(op_start.substr(0, 2)) * 60 + stoi(op_start.substr(3, 2));
    int op_end_num = stoi(op_end.substr(0, 2)) * 60 + stoi(op_end.substr(3, 2));
    
    // skip opening
    if (op_start_num <= pos_num && pos_num < op_end_num) {
        pos_num = op_end_num;
    }
    
    for (int i = 0; i < commands.size(); i++) {
        // prev or next
        if (commands[i] == "prev") {
            pos_num -= 10;
            if (pos_num < 0) pos_num = 0;
        } else {
            pos_num += 10;
            if (pos_num > video_len_num) pos_num = video_len_num;
        }
        
        // skip opening
        if (op_start_num <= pos_num && pos_num < op_end_num) {
            pos_num = op_end_num;
        }
    }
    
    int min = pos_num / 60;
    int sec = pos_num - min * 60;
    
    answer += (min < 10 ? "0" + to_string(min) : to_string(min))
            + ":" 
            + (sec < 10 ? "0" + to_string(sec) : to_string(sec));
    
    return answer;
}