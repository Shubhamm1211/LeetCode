class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        stack <pair <int,int>> st;
        vector <int> ngr(n);
        for(int i = n - 1; i >= 0; i--){
            if(st.empty()){
                ngr[i] = n;
                st.push({nums[i],i});
            }
            else{
                while(!st.empty() and st.top().first <= nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    ngr[i] = n;
                }
                else ngr[i] = st.top().second;
                st.push({nums[i], i});
            }
        }
        vector <int> ans(n);
        for(int i = 0; i < n; i++){
            if(ngr[i] == n) ans[i] = 0;
            else ans[i] = ngr[i] - i;
        }
        return ans;
    }
};