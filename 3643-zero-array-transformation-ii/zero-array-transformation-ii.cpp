class Solution {
public:
    bool check(vector <int> &nums, vector<vector <int>> &q, int k){
        int n = nums.size();
        vector <int> temp(n);
        for(int i = 0; i <= k; i++){
            int l = q[i][0];
            int r = q[i][1];
            int x = q[i][2];
            temp[l] += x;
            if(r < n - 1) temp[r + 1] -= x;
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += temp[i];
            temp[i] = sum;
            if(nums[i] > temp[i]) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        int nq = q.size();
        
        bool f  = true;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0) f = false;
        }
        if(f) return 0;
        int start = 0, end = nq - 1;
        int ans = -1;
        while(start <= end){
            int mid = start + ((end - start) / 2);
            if(check(nums,q,mid)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }

        return (ans == -1) ? -1 : ans + 1 ;
    }
};