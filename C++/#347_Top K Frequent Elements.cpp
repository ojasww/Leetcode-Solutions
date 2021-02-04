class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        if(nums.size()==0) return result;
        unordered_map<int, int> mp;
        for(auto i : nums)
            mp[i]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&lambda)> pq(lambda);
        for(auto m : mp){
            pq.push(make_pair(m.first, m.second));
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
    static bool lambda(const pair<int, int>& a, const pair<int, int>& b){
        return a.second>b.second;
    }
};