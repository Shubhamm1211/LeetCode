class Solution {
public:
    vector <int> temp;
    void solve(int ind, vector <int> &nums, vector <vector <int>> &ans, int tar){
        if(tar == 0){
            ans.push_back(temp);
            return;
        }
        if(ind == nums.size() or tar < 0) return;
        temp.push_back(nums[ind]);
        solve(ind, nums, ans, tar - nums[ind]);
        temp.pop_back();

        solve(ind + 1, nums, ans, tar);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int tar) {
        int n = nums.size();
        vector <vector <int>> ans;
        solve(0,nums,ans,tar);
        return ans;
    }
};
