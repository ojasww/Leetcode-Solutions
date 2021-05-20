class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        map<int, int, greater<int>> mp;
        for(auto a : A)
            mp[a]++;
        for(auto itr = mp.begin(); itr != mp.end(); itr++)
            if(itr->second == 1)
                return itr->first;
        return -1;
    }
};