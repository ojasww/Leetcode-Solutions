class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result;
        unordered_map<string, int> mp;
        for(auto word : words)
            mp[word]++;
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(&lambda)> pq(lambda);
        for(auto word : mp)
            pq.push(make_pair(word.first, word.second));
        int count = k;
        while(count>0){
            result.push_back(pq.top().first);
            pq.pop();
            count--;
        }
        return result;
            
    }
    
    static bool lambda(const pair<string, int>& a, const pair<string, int>& b){
        if(a.second == b.second) return a.first > b.first; 
        return a.second < b.second;
    }
};