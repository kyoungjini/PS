#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int k_tmp = k;
    int cursor = 0;
    
    while (k > 0) {
        char max_val = '0';
        int max_idx;
        
        if (answer.length() >= number.length() - k) break;
        
        for (int i = cursor; i <= cursor + k; i++) {
            if (number[i] > max_val) {
                max_val = number[i];
                max_idx = i;
            }
        }
        
        answer += max_val;
        k -= (max_idx - cursor);
        cursor = max_idx + 1;
    }
    
    if (k > 0) cursor += k;
    
    if (cursor < number.size()) answer += number.substr(cursor);

    return answer;
}