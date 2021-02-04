class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto n : nums) if(n<k) mp[n]++;
        unordered_map<int, int>::iterator itr;
        int result=0;
        for(itr=mp.begin(); itr!=mp.end(); itr++){
            int m = k-(itr->first);
            if(mp.find(m)!=mp.end() && mp[m]>0 && itr->second>0){
                if(m==itr->first){
                    result+=mp[m]/2;
                    mp[m]=0;
                }
                else{
                    int minF = min(itr->second, mp[m]);
                    result+=minF;
                    itr->second-=minF;
                    mp[m]-=minF;
                }
            }
        }
        return result;
    }
};