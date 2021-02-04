class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        int n=nums.size();
        if(n==0) { 
            addRange(lower, upper, result);
            return result;
        } 
        if(lower!=nums[0])
            addRange(lower, nums[0]-1, result);
        int i=0;
        while(i<n-1){
            if(nums[i]+1!=nums[i+1])
                addRange(nums[i]+1, nums[i+1]-1, result);
            i++;
        }
        if(upper!=nums[n-1])
            addRange(nums[n-1]+1, upper, result);
        return result;
    }
    void addRange(int i, int j, vector<string>& result){
        if(i==j) result.push_back(to_string(i));
        else result.push_back(to_string(i)+"->"+to_string(j));
    }
};