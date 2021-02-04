class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        
        if(s.length()==0)
            return true;
    
        for(int i=0; i<s.length(); i++){
           if(s[i]=='(' || s[i]=='[' || s[i]=='{')
               brackets.push(s[i]);
           
           if(s[i]==')'){
               if(brackets.empty())
                   return false;
               else{
                   if(brackets.top() == '(')
                       brackets.pop();
                   else
                       return false;
               }
           }
           if(s[i]==']'){
               if(brackets.empty())
                   return false;
               else{
                   if(brackets.top() == '[')
                       brackets.pop();
                   else
                       return false;
               }
           }
           if(s[i]=='}'){
               if(brackets.empty())
                   return false;
               else{
                   if(brackets.top() == '{')
                       brackets.pop();
                   else
                       return false;
               }
           }
        }
    if(brackets.empty())
        return true;
    else return false;
    }
};