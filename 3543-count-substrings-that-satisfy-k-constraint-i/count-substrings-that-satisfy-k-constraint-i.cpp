class Solution {
public:
    bool check(string s,int k){
        int cnt0=0,cnt1=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')cnt0++;
            else cnt1++;
        }
        if(cnt0<=k or cnt1<=k)return true;
        return false;
    }
    int countKConstraintSubstrings(string s, int k) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            for(int len=1;len<=s.size()-i;len++){
                string sub=s.substr(i,len);
                if(check(sub,k))ans++;
            }
        }
        return ans;
    }
};