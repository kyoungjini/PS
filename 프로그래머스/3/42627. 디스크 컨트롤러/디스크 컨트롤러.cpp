#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int cur_time = 0;
    int idx = 0;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    
    // sort jobs
    vector<vector<int>> sorted_jobs;
    for (int i = 0; i < jobs.size(); i++) {
        sorted_jobs.push_back({jobs[i][0], jobs[i][1], i});
    }
    sort(sorted_jobs.begin(), sorted_jobs.end());
    
    while(idx < sorted_jobs.size() || !pq.empty()) {
        // update queue
        for (int i = 0; i < sorted_jobs.size(); i++) {
            if (idx >= sorted_jobs.size()) break;
            
            if (sorted_jobs[idx][0] <= cur_time) {
                pq.push({sorted_jobs[idx][1], sorted_jobs[idx][0], sorted_jobs[idx][2]});
                idx++;
            } else {
                break;
            }
        }
        
        // take out a task from queue
        if (pq.empty()) {
            cur_time++;
        } else {
            vector<int> task = pq.top();
            pq.pop();
            cur_time += task[0];
            answer += (cur_time - task[1]);
        }
    }
    
    answer /= sorted_jobs.size();
    
    return answer;
}