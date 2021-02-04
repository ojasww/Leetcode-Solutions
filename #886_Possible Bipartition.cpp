class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> nodeColor(N+1, 0);
        vector<int> adj[N+1];
        for(auto dislike : dislikes){
            adj[dislike[0]].push_back(dislike[1]);
            adj[dislike[1]].push_back(dislike[0]);
        }
        queue<int> q;
        for(int i=1; i<=N; i++){
            if(nodeColor[i]==0){
                nodeColor[i]=1;
                q.push(i);
                while(!q.empty()){
                    int size = q.size();
                    for(int i=0; i<size; i++){
                        int node = q.front();
                        q.pop();
                        for(int i=0; i<adj[node].size(); i++){
                            if(nodeColor[adj[node][i]]==nodeColor[node])
                                return false;
                            else{
                                if(nodeColor[adj[node][i]]==0){
                                    int color = nodeColor[node]==1 ? -1 : 1;
                                    nodeColor[adj[node][i]] = color;
                                    q.push(adj[node][i]);
                                }
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};