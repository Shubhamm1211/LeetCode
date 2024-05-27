class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0,l=0,r=0,cnt=0;
        while(r<n){
            if(nums[r]==0)cnt++;
            if(cnt>k){
                if(nums[l]==0)cnt--;
                l++;
            }
            if(cnt<=k){
                maxi=max(maxi,r-l+1);
            }
            r++;
        }
       return maxi;
    }
};