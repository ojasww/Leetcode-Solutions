class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        DFS(graph, 0, path, result);
        return result;
    }
    void DFS(vector<vector<int>>& graph, int i, vector<int>& path, vector<vector<int>>& result){
        path.push_back(i);
        if(i==graph.size()-1) { result.push_back(path); path.pop_back(); return; }
        else {
            for(int j=0; j<graph[i].size(); j++)
                DFS(graph, graph[i][j], path, result);
        }
        path.pop_back();
        return;
    }
};