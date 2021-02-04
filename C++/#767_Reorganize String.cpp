class Solution {
public:
    string reorganizeString(string S) {
        int n=S.size();
        vector<int> letters(26, 0);
        for(auto s : S)
            letters[s-'a']++;
        int maxFreq = -1, letter=-1;
        for(int i=0; i<26; i++){
            if(letters[i]>maxFreq){
                maxFreq = letters[i];
                letter = i;
            }
        }
        if(maxFreq > (n+1)/2)
            return "";
        int i=0;
        while(letters[letter]){
            S[i]='a'+letter;
            letters[letter]--;
            i+=2;
        }
        for(int j=0; j<26; j++){
            while(letters[j]>0){
                if(i>=n)
                    i=1;
                letters[j]--;
                S[i]='a'+j;
                i+=2;
            }
        }
        return S;
    }
};