class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        int ans=0;
        bool flag=true;
        for(auto x:words){
            string org=x;
            if(mp.find(org)!=mp.end()){
                string rev=org;
                reverse(rev.begin(),rev.end());
                if(rev!=org and mp[org]>0 and mp[rev]>0){
                    ans=ans+4;
                    mp[org]--;
                    mp[rev]--;
                }
                else if(rev==org and mp[rev]>1){
                    ans=ans+4;
                    mp[rev]=mp[rev]-2;
                }
                else if(rev==org and flag and mp[rev]>0){
                    ans=ans+2;
                    mp[rev]--;
                    flag=false;
                }
            }
        }
        return ans;
    }
};