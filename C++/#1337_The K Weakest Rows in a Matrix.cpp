class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> vp;
        int count=0;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j])
                    count++;
            }
            vp.push_back(make_pair(count, i));
            count=0;
        }
        sort(vp.begin(), vp.end());
        vector<int> v;
        for(int i=0; i<k; i++){
            v.push_back(vp[i].second);
        }
        return v;
    }
};