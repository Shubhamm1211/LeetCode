class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n=s1.size(),x=0,y=0;
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i])continue;
            else if(s1[i]=='x')x++;
            else y++;
        }
        if((x+y)%2==1)return -1;
        int ans=(x+1)/2 + (y+1)/2 ;
        return ans;
    }
};