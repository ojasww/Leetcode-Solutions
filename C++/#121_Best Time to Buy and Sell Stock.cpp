class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0 || n==1)
            return 0;
        int currMin = prices[0];
        int profit=0;
        for(int i=0; i<n; i++){
            profit=max(profit, prices[i]-currMin);
            currMin=min(currMin, prices[i]);
        }
        return profit;
    }
};