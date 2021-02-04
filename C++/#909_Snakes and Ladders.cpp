class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int path = 0;
        int n = board.size(); 
        if(n==0 || board[0].size()==0) return 0;
        queue<int> q;
        vector<bool> visited(n*n+1, false);
        // vector<int> dist(n*n+1, 0);
        q.push(1);
        visited[1]=true;
        while(!q.empty()){
            int count = q.size();
            for(int i=0; i<count; i++){
                int c = q.front();
                q.pop();
                if(c==n*n) return path;
                for(int j=1; j<=6; j++){
                    if(c+j<=n*n && !visited[c+j]){
                        int x = n - ((c-1)+j)/n - 1;
                        int y = ((n-x-1)%2==0) ? (c+j-1)%n : n-1-((c+j-1)%n);
                        // cout<<x<<" "<<y<<endl;
                        if(board[x][y]==-1)
                            q.push(c+j);
                        else
                            q.push(board[x][y]);
                        visited[c+j] = true;
                    }
                }   
            }
            path++;
        }
        return -1;
    }
};