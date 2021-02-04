class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K%2==0 || K%5==0) return -1;
        int remainder=1%K;
        for(int i=0; i<K; i++){
            if(remainder==0)
                return i+1;
            remainder=((remainder*10)+1) % K;
        }
        return -1;
    }
};