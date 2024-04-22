class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();

        vector<int> dp(size, 0);

        if(s[0] == '0') return 0;
        else {
            dp[0] = 1;
            if(size == 1) return dp[0];

            if(s[1] == '0') {
                if(s[0] - '0'  <= 2) dp[1] = 1;
                else dp[1] = 0;
            } else {
                int num = 0;
                num = (s[0] - '0')*10 + (s[1] - '0');
                if(num<=26) dp[1] = 2;
                else dp[1] = 1;
            }
        }               
        
        for(int i=2; i<size; i++) {
            if(s[i] == '0') {
                if(s[i-1] != '1' && s[i-1] != '2') return 0;
                else dp[i] = dp[i-2]; 
            } else {
                dp[i] = dp[i-1];
                if(s[i-1] == '1'  || s[i-1] == '2') {
                    int num = 0;
                    num = (s[i-1] - '0')*10 + (s[i] - '0');
                    if(num<=26) dp[i] += dp[i-2];
                }
            }
        }

        return dp[size-1];
    }
};