class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(!grid.size()) return 0;
        set<string> stringSet;
        string s;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    s="";
                    DFSTraversal(grid, i, j, s, "o");
                    stringSet.insert(s);
                }
            }
        }
        return stringSet.size();
    }
private: 
    void DFSTraversal(vector<vector<int>>&  grid, int i, int j, string &s, string direction){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return;
        grid[i][j]=0;
        s+=direction;
        DFSTraversal(grid, i+1, j, s, "d");
        DFSTraversal(grid, i, j+1, s, "r");
        DFSTraversal(grid, i-1, j, s, "u");
        DFSTraversal(grid, i, j-1, s, "l");
        s+="b";
    }
};