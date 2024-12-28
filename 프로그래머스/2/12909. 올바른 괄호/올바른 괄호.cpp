#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> s_stack;
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            s_stack.push('(');
        }
        else {
            if(s_stack.empty()) {
                answer = false;
                break;
            }
            else s_stack.pop();
        }
    }
    
    if(!s_stack.empty()) answer = false;

    return answer;
}