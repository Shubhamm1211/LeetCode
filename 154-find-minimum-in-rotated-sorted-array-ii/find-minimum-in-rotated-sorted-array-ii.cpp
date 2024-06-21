class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini=INT_MAX;
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            mini=min(mini,nums[mid]);
            if(nums[mid]==nums[low] and nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }
            if(nums[low]<=nums[mid]){
                mini=min(mini,nums[low]);
                low=mid+1;
            }
            else{
                mini=min(mini,nums[mid]);
                high=mid-1;
            }
        }
        return mini;
    }
};