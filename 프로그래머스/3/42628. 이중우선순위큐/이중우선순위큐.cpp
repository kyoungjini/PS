#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> pq;
    
    for (auto iter: operations) {
        char command = iter[0];
        int num = stoi(iter.substr(2));
        
        if (command == 'I') {
            pq.insert(num);
        } else if (command == 'D' && num == 1) {
            if (pq.size() == 0) continue;
            pq.erase(--pq.end());
        } else if (command == 'D' && num == -1) {
            if (pq.size() == 0) continue;
            pq.erase(pq.begin());
        }
    }
    
    if (pq.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(*--pq.end());
        answer.push_back(*pq.begin());
    }
    
    return answer;
}