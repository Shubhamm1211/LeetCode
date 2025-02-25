class Solution {
public:
    bool solve(vector <int> &nums, int k, int mid){
        int cnt = 1;
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sum += nums[i];
            if(sum > mid){
                cnt++;
                sum = nums[i];
            }
        }
        return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(begin(nums), end(nums));
        int high = accumulate(begin(nums), end(nums), 0);
        int ans = -1;
        while(low <= high){
            int mid = high - ((high - low) / 2);
            if(solve(nums,k,mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};