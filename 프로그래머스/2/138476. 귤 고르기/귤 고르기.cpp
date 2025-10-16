#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int arr[10000001] = {0, };

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    set<int> tang;
    vector<int> cnt;
    
    // complete arr and tang
    for (auto i: tangerine) {
        arr[i]++;
        tang.insert(i);
    }
    
    // complete cnt
    for (auto i: tang) cnt.push_back(arr[i]);
    sort(cnt.rbegin(), cnt.rend());
    
    int idx = 0;
    while (k > 0) {
        k -= cnt[idx];
        answer++;
        idx++;
    }
    
    return answer;
}