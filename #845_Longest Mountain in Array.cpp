class Solution {
public:
    int longestMountain(vector<int>& A) {
        int up=0, down=0, res=0;
        for(int i=1; i<A.size(); i++){
            if(down && A[i-1] < A[i] || A[i] == A[i-1]) up=down=0;
            up += A[i] > A[i-1];
            down += A[i] < A[i-1];
            if(up && down) res = max(res, up+down+1);
        }
        return res;
    }
};