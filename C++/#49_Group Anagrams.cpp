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

/**
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;

        for(auto i: strs) {
            string sortedString = i;
            sort(sortedString.begin(), sortedString.end());

            // cout<<sortedString<<endl;

            mp[sortedString].push_back(i);
        }

        // for(auto i: mp) {
        //     for (auto j: i.second) {
        //         cout<<j<<endl;
        //     }
        //     cout<<endl;
        // }

        vector<vector<string>> answer{mp.size()};
        
        int answerIndex = 0;
        for (auto i: mp) {
            answer[answerIndex] = i.second;
            answerIndex++;
        }

        return answer;
    }
};
*/