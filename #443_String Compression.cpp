class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        for(int j=1, count=1; j<=chars.size(); j++, count++){
            if(j==chars.size() || chars[j-1] != chars[j]){
                chars[i++] = chars[j-1];
                if(count>=2){
                    for(auto c : to_string(count))
                        chars[i++] = c;
                }
                count=0;
            }
        }
        return i;
    }
};
