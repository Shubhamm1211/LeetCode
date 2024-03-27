class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int tsum=0;
        for(auto x:nums)tsum+=x;
        int n=nums.size();
        int sum=0;
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            if(sum<=tsum-sum){
                ans.push_back(nums[i]);
                sum=sum+nums[i];
            }
        }
        return ans;
    }
};