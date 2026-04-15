#include <string>
#include <vector>

using namespace std;

string alphabet[5] = {"A", "E", "I", "O", "U"};
int answer = 0;
int cnt = 0;

void back_tracking(string target, string cur_word) {
    if (cur_word == target) {
        answer = cnt;
        return;
    }
    
    if (cur_word.length() >= 5) return;
    
    for (int i = 0; i < 5; i++) {
        cnt++;
        back_tracking(target, cur_word + alphabet[i]);
    }
}

int solution(string word) {
    back_tracking(word, "");
    return answer;
}