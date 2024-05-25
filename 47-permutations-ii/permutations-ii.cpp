class Solution {
public:
    vector<vector<int>>res;
    void solve(vector<int>nums,int i){
        if(i==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            if(j==i || nums[i]!=nums[j]){
                swap(nums[i],nums[j]);
                solve(nums,i+1);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        solve(nums,i);
        return res;
    }
};