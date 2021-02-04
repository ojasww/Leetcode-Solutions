class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size()==0 || matrix[0].size()==0) return result;
        int rs=0, re=matrix[0].size()-1, cs=0, ce=matrix.size()-1;
        while(rs<=re && cs<=ce){
            for(int i=rs; i<=re; i++)
                result.push_back(matrix[cs][i]);
            cs++;
            for(int i=cs; i<=ce; i++)
                result.push_back(matrix[i][re]);
            re--;
            if(cs<=ce){
                for(int i=re; i>=rs; i--)
                    result.push_back(matrix[ce][i]);
            }
            ce--;
            if(rs<=re){
                for(int i=ce; i>=cs; i--)
                    result.push_back(matrix[i][rs]);
            }
            rs++;
        }
        return result;
    }
};