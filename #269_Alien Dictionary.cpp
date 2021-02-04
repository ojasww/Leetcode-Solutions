class Solution {
public:
    string alienOrder(vector<string>& words) {
        string result="";
        if(words.size()==0) return result;
        map<char, int> degree;
        map<char, unordered_set<char>> pre;
        for(auto word : words){
            for(auto c : word)
                degree[c] = 0;
        }
        for(int i=0; i<words.size()-1; i++){
            string word1 = words[i];
            string word2 = words[i+1];
            int minLength = min(word1.length(), word2.length());
            if(word1.length() > word2.length() && word1.substr(0, minLength) == word2) return result;
            for(int j=0; j<minLength; j++){
                if(word1[j]!=word2[j]){
                    if(pre[word1[j]].find(word2[j]) == pre[word1[j]].end()){
                        pre[word1[j]].insert(word2[j]);
                        degree[word2[j]]++;
                    }
                    break;
                }
            }        
        }
        queue<char> q;
        for(auto d: degree)
            if(d.second==0) q.push(d.first);
        while(!q.empty()){
            char c = q.front();
            q.pop();
            result += c;
            for(auto character : pre[c]){
                degree[character]--;
                if(!degree[character]) q.push(character);
            }
        }
        // cout<<result<<endl;
        if(result.length() != degree.size()) return "";
        return result;
    }
};