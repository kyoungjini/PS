#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int s = 1, e = 100000;
    int mid;
    
    while (s <= e) {
        mid = (s + e) / 2;
        long long time_sum = 0;
        
        for (int i = 0; i < diffs.size(); i++) {
            if (diffs[i] <= mid) time_sum += times[i];
            else {                
                time_sum += (diffs[i] - mid) * (times[i] + times[i - 1]) + times[i];
            }
        }
        
        if (time_sum <= limit) {
            answer = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    
    return answer;
} 