class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer;
        if(!nums.size()) return answer;
        if(nums.size()==1) {answer.push_back(to_string(nums[0])); return answer;}
        int init=0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1]!=nums[i]+1){
                if(i==init)
                    answer.push_back(to_string(nums[i]));
                else
                    answer.push_back(to_string(nums[init]) + "->" + to_string(nums[i]));
                init=i+1;
            }
        }
        if(init==nums.size()-1)
            answer.push_back(to_string(nums[init]));
        else
            answer.push_back(to_string(nums[init]) + "->" + to_string(nums[nums.size()-1]));
        return answer;
    }
};