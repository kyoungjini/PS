#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int> s[9];

int solution(int N, int number) {
    int answer = -1;
    
    string N_str = "";
    for (int i = 1; i <= 8; i++) {
        N_str += to_string(N);
        s[i].insert(stoi(N_str));
    }
    
    for (int i = 2; i <= 8; i++) {
        for (int j = 1; j < i; j++) {
            for (auto a: s[j]) {
                for (auto b: s[i - j]) {
                    s[i].insert(a + b);
                    s[i].insert(a - b);
                    s[i].insert(a * b);
                    if (b != 0) s[i].insert(a / b);
                }  
            }
        }
    }
    
    for (int i = 1; i <= 8; i++) {
        if (s[i].find(number) != s[i].end()) return i;
    }
    
    return answer;
}
