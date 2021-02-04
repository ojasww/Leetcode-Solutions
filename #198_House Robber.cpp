class Solution {
public:
    //cool dp problem
    int rob(vector<int>& nums) {
        int num2 = 0, num1 = 0;
        for(int i=0; i<nums.size(); i++){
            int temp = num1;
            num1 = max(num2 + nums[i], num1);
            num2 = temp;
        }
        return num1;
    }
};