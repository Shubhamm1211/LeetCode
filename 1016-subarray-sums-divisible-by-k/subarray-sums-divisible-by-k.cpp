class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0,ans=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            int rem=sum%k;
            if(rem<0)rem+=k;
            ans=ans+mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};