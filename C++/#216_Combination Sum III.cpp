class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tryout;
        vector<vector<int>> result;
        checkSum(n, 1, k, tryout, result);
        return result;
    }
private:
    void checkSum(int target, int index, int k, vector<int>& tryout, vector<vector<int>>& result){
        if(target<0) return;
        if(target==0 && tryout.size()==k) {result.push_back(tryout); return;}
        for(int i=index; i<=9; i++){
            tryout.push_back(i);
            checkSum(target-i, i+1, k, tryout, result);
            tryout.pop_back();
        }
    }
};