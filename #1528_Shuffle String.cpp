class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int index=0;
        string ans(s.length(), ' ');
        for(int i=0; i<indices.size(); i++){
            ans[indices[i]]=s[index];
            index++;
        }
        return ans;
    }
};