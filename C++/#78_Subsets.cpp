class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tryout;
        backtrack(result, tryout, 0, nums);
        return result;
    }
    void backtrack(vector<vector<int>>& result, vector<int>& tryout, int i, vector<int> nums){
        result.push_back(tryout);
        for(int j=i; j<nums.size(); j++){
            tryout.push_back(nums[j]);
            backtrack(result, tryout, j+1, nums);
            tryout.pop_back();
        }
        return;
    }
};