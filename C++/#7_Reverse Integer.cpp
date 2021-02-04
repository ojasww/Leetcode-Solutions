class Solution {
public:
    int reverse(int x) {
        vector<int> digits;
        while(x!=0){
            digits.push_back(x%10);
            x/=10;
        }
        int n = digits.size();
        long long int num=0;
        for(int i=0; i<digits.size(); i++){
            num+=digits[i]*pow(10, n-1);
            n--;
        }
        if(num>pow(2,31)-1 || num <-1*pow(2,31))
            return 0;
        else
            return num;
    }
};