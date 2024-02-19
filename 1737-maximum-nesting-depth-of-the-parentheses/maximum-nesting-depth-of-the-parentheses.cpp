class Solution {
public:
    int maxDepth(string s) {
        int maxi=INT_MIN;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cnt++;
            }
            else if(s[i]==')'){
                cnt--;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};