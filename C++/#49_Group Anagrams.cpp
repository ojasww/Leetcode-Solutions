class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;
        for(auto s : strs){
            string key(26, '0');
            for(auto c : s) key[c-'a']++;
            mp[key].push_back(s);
        }
        for(auto m : mp) result.push_back(m.second);
        return result;
    }
};