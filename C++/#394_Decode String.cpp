class Solution {
public:
    string decodeString(string s) {
        int index=0;
        return decode(s, index);
    }
    string decode(string s, int& index){
        string res;
        while(index<s.size() && s[index]!=']'){
            string temp = "";
            if(isdigit(s[index])){
                string digits;
                while(isdigit(s[index])) { digits+=s[index]; index++; }
                int number = stoi(digits);
                index++;
                temp = decode(s, index);
                for(int i=0; i<number; i++) res+=temp;
            }
            else res+= s[index];
            index++;
        }
        return res;
    }
};