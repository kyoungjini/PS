#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>&a, vector<int>&b) {
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), cmp);
    
    int s = targets[0][0], e = targets[0][1];
    answer++;
    
    for (int i = 1; i < targets.size(); i++) {
        int ns = targets[i][0];
        int ne = targets[i][1];
        
        if (e <= ns) {
            s = ns; 
            e = ne;
            answer++;
        }
    }
    
    return answer;
}