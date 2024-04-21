class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char>s(word.begin(),word.end());
        int cnt=0;
        for(auto it:s){
            if(isupper(it)){
                char ch=it;
                if(s.find(tolower(ch))!=s.end())cnt++;
            }
        }
        return cnt;
        
    }
};