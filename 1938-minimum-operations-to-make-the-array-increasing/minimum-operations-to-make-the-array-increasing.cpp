class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<=nums[i]){
                int diff=nums[i]-nums[i+1];
                ans=ans+diff+1;
                nums[i+1]=nums[i+1]+diff+1;
            }
        }
        return ans;
    }
};