class Solution {
public:
    vector<int> cs;
    Solution(vector<int>& w) {
        for(auto val : w){
            if(cs.empty())
                cs.push_back(val);
            else
                cs.push_back(cs.back()+val);
        }
    }
    
    int pickIndex() {
        int x = cs.back();
        int random = rand() % x;
        auto itr = upper_bound(cs.begin(), cs.end(), random);
        return itr - cs.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */