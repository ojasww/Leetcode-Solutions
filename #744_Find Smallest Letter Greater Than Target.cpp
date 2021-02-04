class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int index=0, min=INT_MAX, sub=0;
        for(int i=0; i<letters.size(); i++){
            if(letters[i] == target)
                continue;
            sub = letters[i]-target;
            if(target > letters[i])
                sub+=26;
            if(sub<min) {index=i; min=sub;}
        }
        return letters[index];
    }
};