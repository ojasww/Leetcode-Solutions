class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> result;
        bool board[8][8] = {false};
        for(auto queen : queens)
            board[queen[0]][queen[1]]=true;
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                if(i==0 && j==0) continue;
                int x = king[0]+i, y = king[1]+j;
                while(x>=0 && x<=7 && y>=0 && y<=7){
                    if(board[x][y]){
                        result.push_back({x, y});
                        break;
                    }
                    x+=i;
                    y+=j;
                }
            }
        }
        return result;
    }
};