class Solution {
public:
    bool isAnagram(string s, string t) {
        // Solution 1
        // int size1 = s.size();
        // int size2 = t.size();

        // if (size1 != size2) {
        //     // cout<<"not equal"<<endl;
        //     return false;
        // }

        // unordered_map<char, int> mp;

        // for(int i=0; i<size1; i++) {
        //     mp[s[i]]++;
        // }

        // for(int i=0; i<size2; i++) {
        //     mp[t[i]]--;
        // }

        // for (auto i = mp.begin(); i != mp.end(); i++) {
        //     if(i->second != 0) {
        //         return false;
        //     }
        // }

        // return true;

        // Solution 2
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};