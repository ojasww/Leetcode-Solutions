class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for(int i=0; i<order.length(); i++){
            mp[order[i]] = i;
        }
        for(int i=0; i<words.size()-1;i++){
            int j=0;
            while(j != words[i].length() && j != words[i+1].length()){
                if(mp[words[i][j]] < mp[words[i+1][j]])
                    break;
                if(mp[words[i][j]] > mp[words[i+1][j]]){
                    // cout<<words[i][j]<<words[i+1][j]<<endl;
                    return false;
                }
                if(j == words[i+1].length()-1 && j != words[i].length()-1)
                    return false;
                j++;
            }
        }
        return true;
    }
};