class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector <int> pre(n);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++){
            pre[i] = nums[i] + pre[i - 1];
        }
        int sum = pre.back();
        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            int rem = sum - pre[i];
            if((pre[i] - rem) % 2 == 0){
                ans++;
            }
        }
        return ans;
    }
};