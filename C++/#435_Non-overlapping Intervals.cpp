class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&lambda)> pq(lambda);

        for(int i=0; i<intervals.size(); i++) {
            pair<int, int> p;

            p.first = intervals[i][0];
            p.second = intervals[i][1];

            pq.push(p);
        }

        int count = 0;

        pair<int, int> q = pq.top();
        pq.pop();

        while(!pq.empty()) {
            pair<int, int> t = pq.top();
            pq.pop();

            if(q.second > t.first) {
                count++;
            } else {
                q = t;
            }
        }

        return count;
    }
    static bool lambda(const pair<int, int>& a, const pair<int, int>& b){
        if(a.second == b.second) return a.first > b.first; 
        return a.second > b.second;
    }
};