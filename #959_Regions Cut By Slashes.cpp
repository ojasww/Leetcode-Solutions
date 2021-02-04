class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        if(n==0) return 0;
        vector<vector<int>> upGrid(n*3, vector<int> (n*3, 1));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='/'){
                    upGrid[i*3+0][j*3+2] = 0;
                    upGrid[i*3+1][j*3+1] = 0;
                    upGrid[i*3+2][j*3+0] = 0;
                }
                if(grid[i][j]=='\\'){
                    upGrid[i*3+0][j*3+0] = 0;
                    upGrid[i*3+1][j*3+1] = 0;
                    upGrid[i*3+2][j*3+2] = 0;
                }
            }
        }
        return numberOfIslands(upGrid);
    }
private:
    int numberOfIslands(vector<vector<int>> upGrid){
        if(!upGrid.size()) return 0;
        int count=0;
        for(int i=0; i<upGrid.size(); i++){
            for(int j=0; j<upGrid[0].size(); j++){
                if(upGrid[i][j] == 1){
                    DFSTraversal(upGrid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    
    void DFSTraversal(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return;
        grid[i][j]=0;
        DFSTraversal(grid, i+1, j);
        DFSTraversal(grid, i, j+1);
        DFSTraversal(grid, i-1, j);
        DFSTraversal(grid, i, j-1);
    }
};