
class Solution {
public:
    void solve(vector<int>& nums,int i,int n,vector<vector<int>>&res){
        if(i==n){
            res.push_back(nums);
            return;
        }
        for (int j=i;j<n;j++) {
            swap(nums[i],nums[j]);
            solve(nums,i+1,n,res);
            swap(nums[i],nums[j]);  
        }
    }
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>>res;
        int n=nums.size();
        solve(nums,0,n,res);
        return res;
    }
};
