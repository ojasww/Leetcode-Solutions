class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        vector<int> tryout;
        checkSum(candidates, target, 0, tryout, result);
        return result;
    }
private:
    void checkSum(vector<int>& candidates, int target, int index, vector<int>& tryout, vector<vector<int>>& result){
        if(target<0) return;
        if(target==0) {result.push_back(tryout); return;}
        for(int i=index; i<candidates.size(); i++){
            // if(i>index && candidates[i]==candidates[i-1]) continue;
            tryout.push_back(candidates[i]);
            checkSum(candidates, target-candidates[i], i, tryout, result);
            tryout.pop_back();
        }
    }
};