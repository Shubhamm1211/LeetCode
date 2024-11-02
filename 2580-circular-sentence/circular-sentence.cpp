class Solution {
public:
    bool isCircularSentence(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                char prev = s[i - 1];
                char next = s[i + 1];
                if(prev != next){
                    return false;
                }
            }
        }
        if(s.back() != s[0]) return false;
        return true;
    }
};