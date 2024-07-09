class Solution {
public:
    double averageWaitingTime(vector<vector<int>>&v) {
       int n=v.size();
       double ans=0;
       int prev=v[0][0]+v[0][1];
       int wt=prev-v[0][0];
       ans+=wt; 
       for(int i=1;i<n;i++){
        int arr=v[i][0];
        int tot=v[i][1];
        int t;
        if(prev>arr)t=prev+tot;
        else t=arr+tot;
        prev=t;
        ans=ans+t-arr;
       }
       return ans/n;
    }
};