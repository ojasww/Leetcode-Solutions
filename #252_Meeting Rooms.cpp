class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return true;
        sort(intervals.begin(), intervals.end(), lambdaFunction);
        for(int i=0; i<intervals.size()-1; i++){
            if(intervals[i][1] > intervals[i+1][0])
                return false;
        }
        return true;
    }
    static bool lambdaFunction(const vector<int> &a, const vector<int> &b){
        if(a[0] == b[0])
              return a[1] < b[1];
        else  return a[0] < b[0];
    }
};