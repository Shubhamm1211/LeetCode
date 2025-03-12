class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int lb = lower_bound(begin(nums), end(nums), 0) - nums.begin();
        int ub = upper_bound(begin(nums), end(nums), 0) - nums.begin();
        if(lb == ub){
            int pos,neg;
            if(lb >= 0 and lb < n and nums[lb] != 0){
                pos = n - lb;
                neg = lb;
            }
            else{
                pos = n - lb - 1;
                neg = n - pos - 1;
            }
            return max(pos,neg);
        }
        else{
            int pos = n - ub;
            int neg = lb;
            return max(pos,neg);
        }
        return -1;
    }
};