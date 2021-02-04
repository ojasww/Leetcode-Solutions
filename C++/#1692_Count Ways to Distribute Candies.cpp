class Solution {
public:
    int waysToDistribute(int n, int k) {
        int m = 1000000007;
        vector<vector<long long int>> dp(k+1, vector<long long int>(n+1, 0));
        for(int i=0; i<=k; i++)
            dp[i][i] = 1;
        for(int i=1; i<=k; i++){
            for(int j=i+1; j<=n; j++){
                dp[i][j] = ((i*dp[i][j-1])%m + dp[i-1][j-1])%m;
            }
        }
        return dp[k][n];
    }
};