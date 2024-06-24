class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(),ans=0,cnt=0;
        for(int i=0;i<n;i++){
            if((nums[i]==0 and cnt%2==0)||(nums[i]==1 and cnt%2==1)){
                cnt++;
                ans++;
            }
        }
        return ans;
    }
};