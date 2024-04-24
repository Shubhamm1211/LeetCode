class Solution {
public:
    int scoreOfString(string s) {
        int ans=0;
        for(int i=1;i<s.size();i++){
            int diff=abs(s[i]-s[i-1]);
            ans=ans+diff;
        }
        return ans;
    }
};