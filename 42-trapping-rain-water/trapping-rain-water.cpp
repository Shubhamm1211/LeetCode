class Solution {
public:
    int trap(vector<int>&h) {
        int n=h.size();
        vector<int>r(n);
        vector<int>l(n);
        r[0]=h[0];
        for(int i=1;i<n;i++){
            r[i]=max(r[i-1],h[i]);
        }
        l[n-1]=h[n-1];
        for(int j=n-2;j>=0;j--){
            l[j]=max(l[j+1],h[j]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=ans+(min(l[i],r[i])-h[i]);
        }
        return ans;
    }
};