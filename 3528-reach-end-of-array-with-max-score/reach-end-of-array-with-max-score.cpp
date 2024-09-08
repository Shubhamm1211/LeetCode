#define ll long long 
class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        ll i=0,j=1;
        ll n=nums.size();
        ll ans=0;
        while(i<n-1){
            while(j<n-1 and nums[i]>=nums[j]){
                j++;
            }
            ll temp=((j-i)*nums[i]);
            ans=ans+temp;
            i=j;
        }
        // ll ans2=(n-1)*nums[0];
        // if(ans2>ans)return ans2;
        return ans;
    }
};