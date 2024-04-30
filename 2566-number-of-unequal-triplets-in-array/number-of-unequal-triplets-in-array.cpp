class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(nums[i] != nums[j] and nums[i] != nums[k] and nums[j] != nums[k] and i<j and j<k){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};