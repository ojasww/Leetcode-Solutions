class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //Union set
        vector<int> v(n, -1);
        for(int i=0; i<edges.size(); i++){
            int x = findParent(edges[i][0], v);
            int y = findParent(edges[i][1], v);
            if(x==y) return false;
            v[x]=y;
        }
        return edges.size() == n-1;
    }
    int findParent(int x, vector<int> &v){
        if(v[x] == -1) return x;
        return findParent(v[x], v);
    }
};