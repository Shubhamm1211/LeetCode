class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> arr;  
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end()); 
        vector<int> ans(n);
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            vector<int> ind, val;
            ind.push_back(arr[i].second);
            val.push_back(arr[i].first);
            vis[i] = true;
            for (int j = i + 1; j < n; j++) {
                if (abs(arr[j].first - arr[j - 1].first) <= k) {
                    ind.push_back(arr[j].second);
                    val.push_back(arr[j].first);
                    vis[j] = true;
                } 
                else break;
            }
            sort(ind.begin(), ind.end()); 
            sort(val.begin(), val.end()); 
            for (int x = 0; x < ind.size(); x++) {
                ans[ind[x]] = val[x];
            }
        }
        return ans;
    }
};
