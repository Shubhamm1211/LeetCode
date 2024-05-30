class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(),ans=0;
        int ls[3]={-1,-1,-1};
        for(int i=0;i<n;i++){
            ls[s[i]-'a']=i;
            if(ls[0]!=-1 and ls[1]!=-1 and ls[2]!=-1){
                ans=ans+1+min(ls[0],min(ls[1],ls[2]));
            }
            
        }
        return ans;
    }
};