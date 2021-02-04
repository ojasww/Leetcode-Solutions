class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> mp;
        vector<int> result;
        for(int i=0; i<S.size(); i++){
            mp[S[i]] = i;
        }
        int last = 0, start = 0;
        for(int i=0; i<S.size(); i++){
            last = max(last, mp[S[i]]);
            if(last == i){
                result.push_back(last - start + 1);
                start = last + 1;
            }
        }
        return result;
    }
};