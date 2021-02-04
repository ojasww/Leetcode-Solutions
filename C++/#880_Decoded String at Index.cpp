class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long i=0, n=0;
        for(i=0; n<K; i++)
            n = isdigit(S[i]) ? n*(S[i]-'0') : n+1;   
        while(i--){
            if(isdigit(S[i])){
                n/=(S[i]-'0');
                K%=n;
            }
            else{
                if(K%n==0)
                    return string(1, S[i]);
                n--;
            }
        }
        return "a";
    }
};