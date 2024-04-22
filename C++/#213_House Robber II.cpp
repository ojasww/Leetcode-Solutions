class Solution {
public:
    int houseRobber1(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);

        dp[0] = nums[0];
        if (nums.size() == 1) return dp[0];

        dp[1] = max(nums[0], nums [1]);
        if (nums.size() == 2) return dp[1];

        int maxValue = dp[1];
        
        for(int i=2; i<nums.size(); i++) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
            maxValue = max(maxValue, dp[i]);
        }

        return maxValue;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        vector<int> nums1(nums.begin(), nums.end()-1);
        vector<int> nums2(nums.begin()+1, nums.end());

        return max(houseRobber1(nums1), houseRobber1(nums2));
    }
};