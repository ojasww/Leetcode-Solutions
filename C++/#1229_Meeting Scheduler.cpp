class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        vector<int> result;
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int i=0, j=0, start=0, end=0;
        while(i<slots1.size() && j<slots2.size()){
            start = max(slots1[i][0], slots2[j][0]);
            end = min(slots1[i][1], slots2[j][1]);
            // cout<<start<<" "<<end<<endl;
            if(end - start >= duration)
                return {start, start+duration};
            else if(slots1[i][1] >= slots2[j][1])
                j++;
            else
                i++;
        }
        return {};
    }
};

// Priority Queue Solution
// class Solution {
// public:
//     vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
//         priority_queue<vector<int>, vector<vector<int>>, decltype(&lambda)> pq(lambda);
//         for(auto slot : slots1)    
//             if(slot[0]+duration<=slot[1])
//                 pq.push(slot);
//         for(auto slot : slots2)
//             if(slot[0]+duration<=slot[1])
//                 pq.push(slot);
//         int end=0;
//         while(pq.size()>1){
//             end = pq.top()[1];
//             // cout<<end<<endl;
//             pq.pop();
//             if(pq.top()[0]+duration <= end){
//                 // cout<<end<<" "<<pq.top()[0]<<" "<<pq.top()[1]<<endl;
//                 return {pq.top()[0], pq.top()[0]+duration};
//             }
//         }
//         return {};
//     }
//     static bool lambda(const vector<int>& a, const vector<int>& b){
//         if(a[0]==b[0]) return a[1]>b[1];
//         return a[0]>b[0];
//     }
// };
