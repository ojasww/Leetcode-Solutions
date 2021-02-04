class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            int numberToFind = target - nums[i];
            if(mp.find(numberToFind) != mp.end()){
                result.push_back(mp[numberToFind]);
                result.push_back(i);
                return result;
            }
            mp[nums[i]] = i;
        }
        return result;
    }
};