class Solution {
public:
    string customSortString(string order, string s) {
        int on=order.size();
        int sn=s.size();
        string ans="";
        vector<int>vis(sn,-1);
        for(int i=0;i<on;i++){
            char c=order[i];
            for(int j=0;j<sn;j++){
                if(s[j]==c && vis[j]!=1){
                    ans.push_back(s[j]);
                    vis[j]=1;
                }
            }
        }
        for(int i=0;i<sn;i++){
            if(vis[i]==-1){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};