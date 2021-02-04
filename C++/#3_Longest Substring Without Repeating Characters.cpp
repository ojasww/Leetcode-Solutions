class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int j=0, maxValue=0;
        for(int i=0; i<s.size(); i++){
            if(mp.find(s[i])!=mp.end())
                j=max(j, mp[s[i]]+1);
            mp[s[i]]=i;
            maxValue = max(maxValue, i-j+1);
        }
        return maxValue;
    }
};