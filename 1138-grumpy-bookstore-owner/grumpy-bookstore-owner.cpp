class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int min) {
        int n=c.size(),ans=0,maxi=0;
        int curr=0;
        for(int i=0;i<n;i++){
            if(g[i]==0){
                ans+=c[i];
            }
            else if(i<min){
                curr=curr+c[i];
            }  
        }
        maxi=curr;
        for(int i=min;i<n;i++){
            curr=curr+c[i]*g[i];
            curr=curr-c[i-min]*g[i-min];
            maxi=max(maxi,curr);
        }
        return maxi+ans;
    }
};