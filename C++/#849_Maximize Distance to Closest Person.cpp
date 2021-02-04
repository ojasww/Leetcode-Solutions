class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int last = -1;
        int n = seats.size();
        int result=-1;
        for(int i=0; i<n; i++){
            if(seats[i]==1){
                if(last==-1)
                    result=i;
                else
                    result=max(result, (i-last)/2);
                last=i;
            }
        }
        result = max(result, n-last-1);
        return result;
    }
};