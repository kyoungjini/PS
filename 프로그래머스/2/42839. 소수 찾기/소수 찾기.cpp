#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool visited[8] = {false};
unordered_set<int> res;

bool isPrime(int n) {
    if (n < 2) return false;
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    
    return true;
}

void back_tracking(string numbers, string cur_num) {
    
    if (!cur_num.empty()) {
        int num = stoi(cur_num);
        if (isPrime(num)) res.insert(num);
    }
    
    for (int i = 0; i < numbers.length(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            back_tracking(numbers, cur_num + numbers[i]);
            visited[i] = false;
        }
    }
    
}

int solution(string numbers) {
    
    back_tracking(numbers, "");
    
    return res.size();
}