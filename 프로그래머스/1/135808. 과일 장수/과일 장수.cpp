#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int box_num = score.size() / m;
    
    sort(score.begin(), score.end());
    
    int idx = score.size();
    for(int i = 0; i < box_num; i++){
        idx -= m;
        if(idx >= 0){
            answer += score[idx] * m;
        }
        else{
            break;
        }
    }
    
    return answer;
}