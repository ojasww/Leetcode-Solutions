class Solution {
public:
    bool canPermutePalindrome(string s) {
        if(s.size()==0) return true;
        unordered_map<char, int> count;
        for(auto c : s)
            count[c]++;
        int oddCount=0, evenCount=0;
        for(auto m : count)
            if(m.second % 2 == 0) evenCount++;
            else oddCount++;
        if(s.size()%2==0){if(oddCount==0) return true; return false;}
        else{if(oddCount==1) return true; else return false;}
        return false;
    }
};