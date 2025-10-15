#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    vector<string> cache;
    
    for (auto city: cities) {
        
        transform(city.begin(), city.end(), city.begin(), ::toupper);
        
        if (cache.empty()) {
            if (cacheSize > 0) cache.push_back(city);
            answer += 5;
        } else if (!cache.empty()) {
            if (find(cache.begin(), cache.end(), city) == cache.end()) {
                if (cache.size() == cacheSize) cache.erase(cache.begin());
                cache.push_back(city);
                answer += 5;
            } else {
                int idx = find(cache.begin(), cache.end(), city) - cache.begin();
                cache.erase(cache.begin() + idx);
                cache.push_back(city);
                answer += 1;
            }
        }
    }
    
    
    return answer;
}