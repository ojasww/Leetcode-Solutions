class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Solution 1
        // set<int> numsSet;

        // for (int i=0; i<nums.size(); i++) {
        //     numsSet.insert(nums[i]);
        // }

        // return !(numsSet.size() == nums.size());

        // Solution 2
        unordered_map<int, bool> mp;

        for (int i=0; i<nums.size(); i++) {
            if(mp[nums[i]] == true) {
                return true;
            }
            mp[nums[i]]=true;
        }

        return false;

        // Solution 3...
    }
};