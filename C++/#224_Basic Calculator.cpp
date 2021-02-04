class Solution {
public:
    int calculate(string s) {
        stack<int> nums, signs;
        long long int num=0, sign=1, result=0;
        for(char c:s){
            if(isdigit(c))
                num = num*10 + c-'0';
            else{
                result+=sign*num;
                num=0;
                if(c=='+')
                    sign=1;
                else if(c=='-')
                    sign=-1;
                else if(c=='('){
                    nums.push(result);
                    signs.push(sign);
                    result=0;
                    sign=1;
                }
                else if(c==')' && signs.size()){
                    result = result*signs.top()+nums.top();
                    signs.pop(); nums.pop();
                }
            }
        }
        result += sign*num;
        return result;
    }
};