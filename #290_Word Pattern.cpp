class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, int> p;
        map<string, int> s;
        istringstream in(str);
        int n=pattern.size(), i=0;
        for(string word; in>>word; i++){
            if(p[pattern[i]] != s[word])
                return false;
            p[pattern[i]] = s[word] = i+1;
        }
        return i==n;
    }
};