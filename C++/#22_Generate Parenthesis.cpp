class Solution {
public:
    vector<string> answer;
    int N;
    void generate(string p, int countOpen, int countClose) {
        if(countOpen == N && countClose == N) {
            answer.push_back(p);
            return;
        }

        if(countOpen < N){
            p+="(";
            generate(p, countOpen+1, countClose);
            p.pop_back();
        }

        if(countClose < countOpen){
            p+=")";
            generate(p, countOpen, countClose+1);
            p.pop_back();
        }
    
    }
    vector<string> generateParenthesis(int n) {
        N=n;
        string p="";
        generate(p, 0, 0);
        return answer;
    }
};