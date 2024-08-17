#define ll long long
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& h) {
        ll maxi=0;
        ll n=h.size();
        for(int i=0;i<n;i++){
            ll peak=h[i];
            vector<int>temp=h;
            for(int j=i-1;j>=0;j--){
                if(temp[j]>temp[j+1]){
                    temp[j]=temp[j+1];
                }
            }
            for(int j=i+1;j<n;j++){
                if(temp[j]>temp[j-1]){
                    temp[j]=temp[j-1];
                }
            }
            // for(auto x:temp)cout<<x<<" ";
            // cout<<endl;
            ll tempsum=accumulate(temp.begin(),temp.end(),0ll);
            // cout<<tempsum<<endl;
            maxi=max(maxi,tempsum);
        }
        return maxi;
    }
};