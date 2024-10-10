class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack <int> st;
        st.push(0);
        for(int i = 1; i < n; i++){
            if(!st.empty() and nums[i] < nums[st.top()]){
                st.push(i);
            }
        }
        int maxi = INT_MIN;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty()and nums[i] >= nums[st.top()]){
                maxi = max(maxi, i - st.top());
                st.pop();
            }
        }
        if(maxi == INT_MIN){
            return 0;
        }
        else return maxi;
    }
};