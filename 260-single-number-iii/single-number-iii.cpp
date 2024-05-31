class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr=nums[0];
        vector<int>ans;
        for(int i=1;i<nums.size();i++){
            xorr=xorr^nums[i];
        }
        int set=xorr & -(unsigned int)(xorr);
        int e1=0,e2=0;
        for(auto x:nums){
            if(x&set)e1=e1^x;
            else e2=e2^x;
        }
        return {e1,e2};
    }
};