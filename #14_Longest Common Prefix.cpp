class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int j=0;
        string prefix="";
        if(strs.size()==0)
            return prefix;
        int flag=0;
        while(true){
            char c = strs[0][j];
            for(int i=0; i<strs.size(); i++){
                if(strs[i][j]!=c || j==strs[i].size()){
                    flag=1;
                    break; 
                }
            }
            if(flag)
                break;
            prefix+=strs[0][j];
            j++;
        }
        return prefix;
    }
};