#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int sum = 0, idx = 0;
    
    while (1) {
        // last truck
        if (idx == truck_weights.size()) {
            answer += bridge_length;
            break;
        }
        
        // pop truck
        if (q.size() == bridge_length) {
            int tmp_w = q.front();
            sum -= tmp_w;
            q.pop();
        }
        
        // weight over
        if (sum + truck_weights[idx] > weight) {
            q.push(0);
        } else {
            q.push(truck_weights[idx]);
            sum += truck_weights[idx];
            idx++;
        }
        
        answer++;
    }
    
    return answer;
}