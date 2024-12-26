class Solution {
public:
    int solve(vector <int> &nums, int ind, int tar){
        int n = nums.size();
        if(ind == 0){
            if(tar == 0 and nums[0] == 0 ) return 2;
            if(tar == 0 or nums[0] == tar) return 1;
            return 0;
        }
        int pick = 0;
        if(nums[ind] <= tar){
            pick = solve(nums,ind - 1, tar - nums[ind]);
        }
        int npick = solve(nums,ind - 1,tar);

        return pick + npick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int tot = accumulate(begin(nums), end(nums), 0);
        int req = (target + tot) / 2;
        if((target + tot) & 1) return 0;
        return solve(nums,n - 1, req);
    }
};