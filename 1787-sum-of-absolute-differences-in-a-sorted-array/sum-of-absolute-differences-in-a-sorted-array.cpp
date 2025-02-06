class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans;
        vector <int> pre(n);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++){
            pre[i] = pre[i - 1] + nums[i];
        }
        for(int i = 0; i < n; i++){
            int lsum = pre[i] - nums[i];
            int rsum = pre.back() - pre[i];
            int tot1 = i * nums[i] - lsum;
            int tot2 = rsum - ((n - i - 1 ) * nums[i]);
            ans.push_back(tot1 + tot2);
        }
        return ans;
    }
};