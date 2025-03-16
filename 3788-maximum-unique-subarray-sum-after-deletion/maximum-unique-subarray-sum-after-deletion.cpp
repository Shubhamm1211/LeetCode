class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(rbegin(nums), rend(nums));
        int sum = 0;
        set <int> st;
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(st.count(nums[i]) == 0){
                sum += nums[i];
                maxi = max(maxi, sum);
                st.insert(nums[i]);
            }
        }
        return maxi;
    }
};