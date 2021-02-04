class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<int> indegree(numCourses, 0);
        vector<int> adj[numCourses];
        for(auto p : prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]+=1;
        }
        //Topological sort with BFS
        queue<int> q;
        for(int i=0; i<numCourses; i++)
            if(indegree[i]==0) q.push(i);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            visited[node]=true;
            for(auto j : adj[node]){
                indegree[j]--;
                if(indegree[j] == 0) q.push(j);
            }
        }
        for(auto b : visited)
            if(!b) return false;
        return true;
    }
};