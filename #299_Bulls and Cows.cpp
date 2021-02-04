class Solution {
public:
    string getHint(string secret, string guess) {
        int size = secret.size();
        int s=0, g=0, A=0, B=0;
        unordered_map<int, int> s_map;
        unordered_map<int, int> g_map;
        for(int i=0; i<size; i++){
            s=secret[i];
            g=guess[i];
            if(s==g)
                A++;
            else{
                (s_map[g] > 0) ? s_map[g]-- , B++ : g_map[g]++;
                (g_map[s] > 0) ? g_map[s]-- , B++ : s_map[s]++;
            }
        }
        return to_string(A)+'A'+to_string(B)+'B';
    }
};