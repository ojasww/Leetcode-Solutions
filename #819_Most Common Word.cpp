class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> mp;
        for(auto & c : paragraph) c = isalpha(c) ? tolower(c) : ' '; 
        istringstream iss(paragraph);
        string word;
        pair<string, int> maxPair("", 0);
        while(iss >> word){
            // cout<<word<<endl;
            if(find(banned.begin(), banned.end(), word) == banned.end()){
                if(++mp[word] > maxPair.second){
                    maxPair.first = word;
                    maxPair.second = mp[word];
                }
            }
        }
        return maxPair.first;
    }
};