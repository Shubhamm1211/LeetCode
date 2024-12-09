class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        for(int i = 0; i < n; i++){
            if(nums[i] < k) return -1;
        }
        set <int> st;
        for(int i = 0; i < n; i++){
            if(nums[i] > k) st.insert(nums[i]);
        }
        return st.size();
    }
};