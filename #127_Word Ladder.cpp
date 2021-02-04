class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int len = 0;
        while(!q.empty()){
            int count = q.size();
            for(int i=0; i<count; i++){
                string word = q.front(); 
                q.pop();
                if(word==endWord) return len+1;
                for(int j=0; j<word.size(); j++){
                    char store = word[j];
                    for(int k=0; k<26; k++){
                        word[j] = 'a' + k;
                        vector<string>::iterator itr;
                        if(wordSet.find(word) != wordSet.end())
                            q.push(word);
                            wordSet.erase(word);
                    }
                    word[j] = store;
                }
            }
            len++;
        }
        return 0;
    }
};