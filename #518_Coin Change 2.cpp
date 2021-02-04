class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //dp, 2D table
        int m = coins.size();
        if (amount == 0) return 1;
        if(m==0) return 0;
        int dp[amount+1][m];
        for(int j=0; j<m; j++)
            dp[0][j] = 1;
        for(int i=1; i<=amount; i++){
            for(int j=0; j<m; j++){
                dp[i][j] = ((j>0) ? dp[i][j-1] : 0) +  ((i-coins[j] >=0) ? dp[i-coins[j]][j] : 0);
            }
        }
        return dp[amount][m-1];
    }
};

//There exists a single array optimization
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         vector<int> dp(amount+1, 0);
//         dp[0] = 1;
//         for (int coin : coins) {
//             for (int i = coin; i <= amount; i++) {
//                 dp[i] += dp[i-coin];
//             }
//         }
//         return dp[amount];
//     }
// };