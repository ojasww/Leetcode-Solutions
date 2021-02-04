class Solution {
public:
        bool isLongPressedName(string name, string typed) {
        int i=0;
            for(int j=0; j<typed.length(); j++){
                if(i<name.length() && typed[j] == name[i])
                    i++;
                else if(j==0 || typed[j] != typed[j-1])
                    return false;
            }
            return i==name.length();
        }
};