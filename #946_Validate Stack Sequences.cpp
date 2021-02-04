class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int index=0;
        stack<int> s;
        for(int i=0 ; i<n; i++){
            s.push(pushed[i]);
            while(!s.empty() && s.top() == popped[index]){
                s.pop();
                index++;
            }
        }
        if(index==n)
            return true;
        return false;
    }
};