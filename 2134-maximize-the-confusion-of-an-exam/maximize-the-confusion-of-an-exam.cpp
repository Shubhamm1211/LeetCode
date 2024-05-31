class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mp;
        int r=0,l=0,ans=0,maxf=0;
        for(r=0;r<n;r++){
            mp[s[r]]++;
            maxf=max(maxf,mp[s[r]]);
            if(r-l+1-maxf>k){
                mp[s[l]]--;
                l++;
            }
            else ans=max(ans,r-l+1);
        }
        return ans;
    }
};