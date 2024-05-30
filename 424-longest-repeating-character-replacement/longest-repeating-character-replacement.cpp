class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int n=s.size();
        int ans=0,l=0,r=0,maxf=0;
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