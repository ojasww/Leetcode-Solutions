class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int> v1, const vector<int> v2){
            return v1[1]-v1[0] > v2[1]-v2[0];
        });
        int s=costs.size(), cost=0;
        for(int  i=0; i<s/2; i++)
            cost+=costs[i][0];
        for(int  i=s/2; i<s; i++)
            cost+=costs[i][1];
        return cost;
    }
};