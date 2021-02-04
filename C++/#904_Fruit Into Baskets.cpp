class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int type1=0, type2=0, count=0, currentLength=0, result=0;
        for(int i=0; i<tree.size(); i++){
            currentLength = tree[i]==type1 || tree[i]==type2 ? currentLength+1 : count + 1;
            if(type2==tree[i])
                count++;
            else{
                count=1;
                type1=type2;
                type2=tree[i];
            }
            result = max(result, currentLength);
        }
        return result;
    }
};