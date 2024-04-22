class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        set<int> s;

        for(int i=0; i<nums.size(); i++) {
            s.insert(nums[i]);
        }

        set<int>::iterator it = s.begin();

        int firstValue = *it;
        it++;

        if(it == s.end())
            return 1;

        int maxCount = 1;
        int count = 1;

        for (set<int>::iterator it1 = it; it1 != s.end(); ++it1) {
            if(*it1 != firstValue + 1){
                maxCount = max(count, maxCount);
                count = 1;
            } else {
                count++;
                cout<<"else"<<count<<endl;
            }
            firstValue = *it1;
        }

        maxCount = max(count, maxCount);
        return maxCount; 
    }
};