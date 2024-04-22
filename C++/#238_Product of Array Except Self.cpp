class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        result[0]=1;
        for(int i=1; i<nums.size(); i++){
            result[i] = result[i-1]*nums[i-1];
        }
        int temp = 1;
        for(int i=nums.size()-1; i>=0; i--){
            result[i] *= temp;
            temp *= nums[i];
        }
        return result;
    }

    /**
        // Store the prefix and suffix values for any given element, build on the solution
        vector<int> answer(nums.size());

        int prefProduct = 1;
        int suffProduct = 1;

        for (int i=0; i<nums.size()-1; i++){
            prefProduct *= nums[i];
            answer[i+1] = prefProduct;
        }

        for (int i=nums.size()-1; i>0; i--){
            suffProduct *= nums[i];
            answer[i-1] *= suffProduct;
        }

        int product = 1;
        for (int i=1; i<nums.size(); i++){
            product *= nums[i]; 
        }
        answer[0] = product;
        
        return answer;
    */
};