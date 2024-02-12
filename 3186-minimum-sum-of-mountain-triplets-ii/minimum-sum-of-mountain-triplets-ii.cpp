class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>right(n);
        vector<int>left(n);
        int rmin=INT_MAX;
        int lmin=INT_MAX;
        for(int i=0;i<n;i++){
            lmin=min(lmin,nums[i]);
            left[i]=lmin;
        }
        for(int i=n-1;i>=0;i--){
            rmin=min(rmin,nums[i]);
            right[i]=rmin;
        }
        int ans=INT_MAX;
        for(int i=1;i<n-1;i++){
            if(left[i]<nums[i] && nums[i]>right[i]){
                ans=min(ans,left[i]+nums[i]+right[i]);
            }
        }
        if(ans==INT_MAX)return -1;
        else return ans;
    }
};