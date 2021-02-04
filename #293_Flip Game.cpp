class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        if(s.size()==0) return result;
        for(int i=0; i<s.size()-1; i++)
            if(s[i]=='+' && s[i+1]=='+'){
                string str = s;
                str[i] = '-'; str[i+1]='-';
                result.push_back(str);
            }
        
        return result;
    }
};