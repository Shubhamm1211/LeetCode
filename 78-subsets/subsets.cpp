class Solution {
public:
    // Backtracking
    // void solve(vector<int>nums,int i,int n,vector<int>&ds,vector<vector<int>>&ans){
    //     if(i==nums.size()){
    //     ans.push_back(ds);
    //     return;
    //     }
    //     ds.push_back(nums[i]);
    //     solve(nums,i+1,n,ds,ans);
    //     ds.pop_back();
    //     solve(nums, i + 1,n, ds, ans);
    // }
    vector<vector<int>>ans2(vector<int>&nums){
        int n=nums.size();
        vector<vector<int>>res;
        int size=1<<n;
        for(int i=0 ; i < (1<<n) ; i++){
            vector<int>temp;
            for(int j = 0 ; j < n ; j++ ){
                if( (i & (1<<j) ) != 0){
                    temp.push_back(nums[j]);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans=ans2(nums);
        // int i=0;
        // int n=nums.size();
        // vector<int>ds;
        // solve(nums,0,n,ds,ans);
        return ans;
        // return ans;
    }
};