class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int> (n, 0));
        int rs=0, re=n-1, cs=0, ce=n-1;
        int value=1;
        while(rs<=re){
            for(int i=rs; i<=re; i++, value++)
                v[cs][i]=value;
            cs++;
            for(int i=cs; i<=ce; i++, value++)
                v[i][re]=value;
            re--;
            for(int i=re; i>=rs; i--, value++)
                v[ce][i]=value;
            ce--;
            for(int i=ce; i>=cs; i--, value++)
                v[i][rs]=value;
            rs++;
        }
        return v;
    }
};