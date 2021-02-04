class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morseCode[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> s;
        for(int i=0; i<words.size(); i++){
            string code;
            for(int j=0; j<words[i].length(); j++){
                code+=morseCode[words[i][j]-'a'];
            }
            s.insert(code);
        }
        return s.size();
    }
};