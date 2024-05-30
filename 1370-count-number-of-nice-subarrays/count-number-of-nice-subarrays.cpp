class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int,int>mp;
        mp[0]=1;
        int n=nums.size(),ans=0,od=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1)od++;
            if(mp.find(od-k)!=mp.end()){
                ans=ans+mp[od-k];
            }
            mp[od]++;
        }
        return ans;
    }
};