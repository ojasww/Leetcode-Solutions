class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;

        int stair1 = 1;
        int stair2 = 2;

        int answer = stair1 + stair2;

        for(int i=2; i<n; i++){
            answer = stair1 + stair2;
            stair1 = stair2;
            stair2 = answer;
        }

        return answer;
    }
};