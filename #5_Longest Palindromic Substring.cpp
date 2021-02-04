class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength=1, startIndex=0;
        int len = s.length();
        if(len<=1) return s;
        bool dp[len][len];
        for(int i=0; i<len; i++)
            dp[i][i]=true;
        for(int i=len-1; i>=0; i--){
            for(int dist=1; dist<len-i; dist++){
                int j=i+dist;
                dp[i][j] = dist==1 ? (s[i]==s[j]) : (s[i]==s[j] && dp[i+1][j-1]);
                if(dp[i][j] && j-i+1 > maxLength){
                    maxLength=j-i+1;
                    startIndex=i;
                }
            }
        }
        return s.substr(startIndex, maxLength);
    }
};