class Solution {
public:
    int tribonacci(int n) {
        int num0=0, num1=1, num2=1, result=0;
        if(n==0) return num0;
        if(n==1) return num1;
        if(n==2) return num2;
        for(int i=3; i<n+1; i++){
            result=num0+num1+num2;
            num0=num1;
            num1=num2;
            num2=result;
        }
        return result;
    }
};