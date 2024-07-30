class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>preb(n),suffa(n);
        preb[0]=s[0]=='b';
        suffa[0]=count(s.begin(),s.end(),'a');
        for(int i=1;i<n;i++){
            preb[i]=preb[i-1]+(s[i]=='b');
            suffa[i]=suffa[i-1]-(s[i-1]=='a');
        }
        int ans=n;
        for(int i=0;i<n;i++){
            ans=min(ans,preb[i]+suffa[i]-1);
        }
        return ans;
    }
};





