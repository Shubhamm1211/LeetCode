class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int>org(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        nums.pop_back();
        for(int i=0;i<nums.size();i++){
            if(maxi<nums[i]*2)return -1;
        }
        for(int i=0;i<org.size();i++){
            if(maxi==org[i])return i;
        }
        return -1;
    }
};