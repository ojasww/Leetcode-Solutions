class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int zero_count=0, one_count=0;
        for(int i=1; i<S.length(); i++){
            if(S[i]=='0')
                zero_count++;
        }
        int minValue=zero_count;
        for(int i=1; i<S.length(); i++){
            if(S[i]=='0')
                zero_count--;
            if(S[i-1]=='1')
                one_count++;
            
            minValue= min(minValue, zero_count+one_count);
            // cout<<"z: "<<zero_count<<" "<<"one: "<<one_count<<" "<<minValue<<" ";
        }
        return minValue;
    }
};