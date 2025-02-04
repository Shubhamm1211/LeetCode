class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxi1 = *max_element(begin(nums), end(nums));
        int sum = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i - 1]){
                sum += nums[i];
                maxi1 = max(maxi1,sum);
            }
            else sum = nums[i];
        }
        maxi1 = max(maxi1,sum);
        return maxi1;
    }
};