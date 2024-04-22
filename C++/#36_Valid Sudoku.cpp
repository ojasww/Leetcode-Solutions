class Solution {
public:
    bool isSetValid(vector<char> v) {
        // stores count
        unordered_map<int, int> mp;

        // We know the length of v is maximum 9
        for (auto i: v){
            if (i == '.') continue;
            
            // convert to int
            int iv = i - '0';

            if(iv > 9 || iv < 0) return false;

            mp[i]++;

            if (mp[i] > 1) return false;
        }

        return true; 
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows
        for(int i=0; i<9; i++){
            bool valid = isSetValid(board[i]);
            if (!valid) return valid;
        }    

        // check columns
        for(int k=0; k<9; k++) {
            for(int i=0; i<9; i++){
                vector<char> v;
                for(int i=0; i<9; i++){
                    v.push_back(board[i][k]);
                }

                bool valid = isSetValid(v);
                if (!valid) return valid;
            }
        }

        // check mini squares
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                vector<char> mini;
                for(int k=i*3; k<i*3+3; k++){
                   for(int l=j*3; l<j*3+3; l++){
                        mini.push_back(board[k][l]);
                    } 
                }

                bool valid = isSetValid(mini);
                if (!valid) return valid;
            }
        }

        return true;
    }

    // A really elegant alternate solution is to encode it in strings and add it to a set, the beauty of math is here!
};