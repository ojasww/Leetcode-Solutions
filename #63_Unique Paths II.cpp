class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(m==0 || n==0) return 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][1]=1;
            
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(obstacleGrid[i-1][j-1] != 1)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};