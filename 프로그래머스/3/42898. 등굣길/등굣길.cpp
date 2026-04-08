#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int dp[101][101] = {0};
    
    dp[1][1] = 1;
    
    for (int i = 0; i < puddles.size(); i++) {
        int x = puddles[i][0], y = puddles[i][1];
        dp[x][y] = -1;
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // home
            if (i == 1 && j == 1) continue;
            
            // puddle
            if (dp[i][j] == -1) continue;
            
            // dp
            if (dp[i - 1][j] == -1 && dp[i][j - 1] == -1) continue;
            else if (dp[i - 1][j] == -1) dp[i][j] = dp[i][j - 1] % 1000000007;
            else if (dp[i][j - 1] == -1) dp[i][j] = dp[i - 1][j] % 1000000007;
            else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
        }
    }
    
    return dp[m][n];
}