class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col_size = matrix.size();
        if(col_size==0) return false;
        int row_size =  matrix[0].size();
        if(row_size==0) return false;
        int lo = 0, hi = col_size*row_size-1;
        while(lo<=hi){
            int mid_index = (lo+hi)/2;
            int mid_value = matrix[mid_index/row_size][mid_index%row_size];
            if(mid_value==target)
                return true;
            else if(mid_value < target)
                lo = mid_index+1;
            else
                hi = mid_index-1;
        }
        return false;
    }
};