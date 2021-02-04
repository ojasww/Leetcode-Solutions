class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<bool> visited(isConnected.size(), false);
        for(int i=0; i<isConnected.size(); i++){
            if(!visited[i]){
                DFS(isConnected, visited, i);
                count++;
            }
        }
        return count;
    }
    void DFS(vector<vector<int>>& isConnected, vector<bool>& visited, int node){
        visited[node] = true;
        for(int i=0; i<isConnected[node].size(); i++){
            if(i!=node && isConnected[node][i] && !visited[i])
                DFS(isConnected, visited, i);
        }
        return;
    }
};