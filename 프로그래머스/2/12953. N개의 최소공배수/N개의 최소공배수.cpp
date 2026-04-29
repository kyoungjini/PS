#include <string>
#include <vector>

using namespace std;

int GCD(int x, int y) {
    int a = max(x, y);
    int b = min(x, y);
    
    while (a % b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    
    return b;
}

int solution(vector<int> arr) {
    int answer = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        int gcd = GCD(answer, arr[i]);
        int lcm = answer * arr[i] / gcd;
        answer = lcm;
    }
    
    return answer;
}