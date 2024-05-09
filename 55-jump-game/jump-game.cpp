class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int ti=n-1;
        for(int i=n-2;i>=0;i--){
            if(i+nums[i]>=ti){
                ti=i;
            }
        }
        if(ti==0)return true;
        return false;
    }
};