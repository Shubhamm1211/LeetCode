class Solution {
public:
    bool rotateString(string s, string g) {
        if(s==g)return true;
        else{
            if(s.size()!=g.size())return false;
            else{
                int n=s.size();
                while(n--){
                    s=s.substr(1)+s[0];
                    if(s==g)return true;
                }
                return false;
            }
        }
    }
};