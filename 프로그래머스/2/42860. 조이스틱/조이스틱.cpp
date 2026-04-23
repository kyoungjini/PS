#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.length();
    
    // change alphabet
    for (char iter: name)  {
        int diff = iter - 'A';
        answer += min(diff, 26 - diff);
    }
        
    // move cursor
    int move = n - 1;
    for (int i = 0; i < n; i++) {
        int next = i + 1;

        while (next < n && name[next] == 'A') {
            next++;
        }

        move = min(move, min(i * 2 + n - next, (n - next) * 2 + i));
    }
    answer += move;
    
    return answer;
}