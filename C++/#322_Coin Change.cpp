class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max = amount+1;
        vector<int> dp(amount+1, max);
        dp[0] = 0;
        for(int i=1; i<amount+1; i++){
            for(int j=0; j<coins.size(); j++){
                if(coins[j]<=i)
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
        return (dp[amount] > amount ? -1 : dp[amount]);
    }
};

/**
class Solution {
public:
    int memoize(vector<int>& coins, int amount, vector<int>& dp) {
        if(amount < 0) return INT_MAX;
        if(amount == 0) return 0;

        if(dp[amount] != -1) return dp[amount];

        int minMemoizedValue = INT_MAX;
        for(auto i: coins) {
            int value = memoize(coins, amount - i, dp);
            if(value != INT_MAX) {
                minMemoizedValue = min(minMemoizedValue, value + 1);
            }
        }

        dp[amount] = minMemoizedValue;
        return minMemoizedValue;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);

        int answer = memoize(coins, amount, dp);

        if (answer == INT_MAX) return -1;

        return answer;
    }
};
*/