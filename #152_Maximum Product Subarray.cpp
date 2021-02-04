class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result=nums[0], l=0, r=0, n=nums.size();
        for(int i=0; i<n; i++){
            l = (l ? l : 1)*nums[i];
            r = (r ? r : 1)*nums[n-i-1];
            result = max(result, max(l ,r));
        }
        return result;
    }
};