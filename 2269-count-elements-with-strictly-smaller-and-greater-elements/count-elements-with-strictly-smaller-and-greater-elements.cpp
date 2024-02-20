class Solution {
public:
    int countElements(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]>mini && nums[i]<maxi)ans++;
        }
        return ans;
    }
};