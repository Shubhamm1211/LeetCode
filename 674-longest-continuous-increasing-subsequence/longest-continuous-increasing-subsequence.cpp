class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        vector<int> res(nums.size(),1);
        
        for(int i=1;i<nums.size();i++){
                if(nums[i]>nums[i-1])
                    res[i]+=res[i-1];
        }
        
        return *max_element(res.begin(),res.end());
    }
};