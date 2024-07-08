class Solution {
public:
    int maxProduct(vector<int>& arr) {
        double maxi=INT_MIN,pre=1,suff=1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(pre==0)pre=1;
            if(suff==0)suff=1;
            pre=pre*arr[i];
            suff=suff*arr[n-i-1];
            maxi=max({maxi,pre,suff});
        }
        return maxi;
    }
};