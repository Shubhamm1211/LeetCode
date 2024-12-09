class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& q) {
        vector<bool> ans(q.size(), false);
        vector<int> vis(nums.size(), 0);
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] % 2 == nums[i - 1] % 2) {
                vis[i] = vis[i - 1];
                vis[i]++;
            } else {
                vis[i] = vis[i - 1];
            }
        }
        for(auto x : vis) {
            cout << x << " ";
        }
        cout << endl;
        if(nums.size() > 1) {
            if(nums[nums.size() - 2] % 2 == nums.back() % 2) {
                nums.back() = 1;
            }
        }
        for(int i = 0; i < q.size(); i++) {
            if(vis[q[i][0]] == vis[q[i][1]]) {
                ans[i] = true;
            }
        }
        return ans;
    }
};
