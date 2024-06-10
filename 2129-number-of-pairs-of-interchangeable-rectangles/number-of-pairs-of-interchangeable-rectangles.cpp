class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& r) {
        unordered_map<double,long long>mp;
        int n=r.size();
        for(int i=0;i<n;i++){
            double a=r[i][0];
            double b=r[i][1];
            mp[a/b]++;
        }
        long long ans=0;
        for(auto x:mp){
            if(x.second>1){
                long long t=x.second;
                ans=ans+t*(t-1)/2;
            }
        }
        return ans;
    }
};