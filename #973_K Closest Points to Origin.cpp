class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        priority_queue<vector<int>, vector<vector<int>>, decltype(&lambda)> pq(lambda);
        for(auto v : points){
            pq.push(v);
            if(pq.size()>K) pq.pop();
        }
        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
    static bool lambda(const vector<int>& a, const vector<int>& b){
        return sqrt(a[0]*a[0] + a[1]*a[1]) < sqrt(b[0]*b[0] + b[1]*b[1]);
    }
};