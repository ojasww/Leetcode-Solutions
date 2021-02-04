class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), lambda);
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto interval : intervals){
            if(!pq.empty() && interval[0] >= pq.top()) pq.pop();
            pq.push(interval[1]);
        }
        return pq.size();
    }
    static bool lambda(const vector<int> &a, const vector<int> &b){
        return a[0]<b[0];
    }
};