class Solution {
public:
    int jump(vector<int>& nums) {
        int jumpCount=0, currEnd=0, currFarthest=0;
        for(int i=0; i<nums.size()-1; i++){
            currFarthest = max(currFarthest, i+nums[i]);
            if(i==currEnd){
                jumpCount++;
                currEnd = currFarthest;
            }
        }
        return jumpCount;
    }
};