class Solution {
public:
    bool check(vector <int> &nums, int k, int mid){
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= mid){
                ans++;
                i++;
            }
        }
        return ans >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *min_element(begin(nums), end(nums));
        int high = *max_element(begin(nums),end(nums));
        int ans = -1;
        while(low <= high){
            int mid = low + ((high - low) / 2);
            if(check(nums,k,mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};