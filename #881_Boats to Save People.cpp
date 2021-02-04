class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //greedy
        int lo=0, hi=people.size()-1;
        int count=0;
        sort(people.begin(), people.end());
        while(lo<=hi){
            if(hi==lo) {count++; break;}
            else{
                if(people[lo] + people[hi] <= limit)
                    lo++;
                hi--;
                count++;
            }
        }
        return count;
    }
};