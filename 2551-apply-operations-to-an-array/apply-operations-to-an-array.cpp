class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == nums[i + 1]){
                nums[i] = nums[i] * 2;
                nums[i + 1] = 0;
            }
        }
        vector <int> ans(n);
        int curr = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                ans[curr] = nums[i];
                curr++;
            }
        }
        for(int i = curr; i < n; i++){
            ans[i] = 0;
        }
        return ans;
    }
};