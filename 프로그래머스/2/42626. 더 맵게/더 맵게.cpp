#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    while(pq.top() < K) {
        if (pq.size() < 2) return -1;
        
        int food1 = pq.top(); pq.pop();
        int food2 = pq.top(); pq.pop();
        
        pq.push(food1 + food2 * 2);
        answer++;
    }
    
    return answer;
}