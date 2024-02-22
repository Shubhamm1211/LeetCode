class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int maxi=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(nums[i]+nums[j]==0){
                    maxi=max(maxi,max(nums[i],nums[j]));
                }
            }
        }
        return maxi;
    }
};