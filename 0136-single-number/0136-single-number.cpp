class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto vec:nums){
            ans=ans^vec;
            
        }
        return ans;
    }
};