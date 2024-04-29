class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xr=0;
        for(auto x:nums)xr=xr^x;
        int ans=xr^k;
        int cnt=0;
        while(ans!=0){
            if(ans&1==1)cnt++;
            ans=ans>>1;
        }
        return cnt;
    }
};