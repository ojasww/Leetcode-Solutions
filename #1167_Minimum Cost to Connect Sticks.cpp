class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto stick : sticks)
            pq.push(stick);
        int cost = 0;
        while(pq.size()>1){
            int stick1 = pq.top(); 
            pq.pop();
            int stick2 = pq.top(); 
            pq.pop();
            pq.push(stick1+stick2);
            cost += stick1+stick2;
        }
         return cost;   
    }
};