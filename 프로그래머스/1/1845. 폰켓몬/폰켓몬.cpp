#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int num_type = 0;
    unordered_map<int, int> m;
    
    for (int i = 0; i < nums.size(); i++) {
        if (m[nums[i]] == 0) num_type++;
        
        m[nums[i]]++;
    }
    
    if (nums.size() / 2 <= num_type) answer = nums.size() / 2;
    else answer = num_type;
    
    return answer;
}