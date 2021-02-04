class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int word1index=-1, word2index=-1, minDis=INT_MAX;
        for(int i=0; i<words.size(); i++){
            if(words[i]==word1){
                word1index=i;
                if(word2index!=-1)
                    minDis=min(minDis, abs(word2index-word1index));
            }
            else if(words[i]==word2){
                word2index=i;
                if(word1index!=-1)
                    minDis=min(minDis, abs(word2index-word1index));
            }
        }
        return minDis;
    }
};