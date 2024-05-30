class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int>mp;
        int ans=0,count=0,sum=0;
        mp[0]=1;
        for(auto x:nums){
            sum+=x;
            if(mp.find(sum-goal)!=mp.end()){
              ans=ans+mp[sum-goal];
            }
            mp[sum]++;
        }
        return ans;
    }
};
