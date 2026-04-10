#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    long long min_t = 1;
    long long max_t = n * (long long)times[times.size() - 1];
    
    while (min_t <= max_t) {
        long long cur_t = (min_t + max_t) / 2;
        long long capacity = 0;
        
        for (int i = 0; i < times.size(); i++) {
            capacity += (cur_t / (long long)times[i]);
        }
        
        if (capacity >= n) {
            answer = cur_t;
            max_t = cur_t - 1;
        } else {
            min_t = cur_t + 1;
        }
    }
    
    return answer;
}