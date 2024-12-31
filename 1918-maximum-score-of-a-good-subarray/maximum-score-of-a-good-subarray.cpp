class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> nsr(n), nsl(n);
        stack< pair<int,int> > st;
        for(int i = n - 1; i >= 0; i--){
            if(st.empty()){
                nsr[i] = n;
                st.push({nums[i], i});
            }
            else{
                while(!st.empty() and st.top().first >= nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsr[i] = n;
                }
                else{
                    nsr[i] = st.top().second;
                }
                st.push({nums[i], i});
            }
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i = 0; i < n; i++){
            if(st.empty()){
                nsl[i] = -1;
                st.push({nums[i], i});
            }
            else{
                while(!st.empty() and st.top().first >= nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsl[i] = -1;
                }
                else{
                    nsl[i] = st.top().second;
                }
                st.push({nums[i], i});
            }
        }
        int maxi = 0;
        for(int i = 0; i < n; i++){
            if(nsl[i] < k and k < nsr[i]){
                maxi = max(maxi, nums[i] * (nsr[i] - nsl[i] - 1));
            }
        }
        return maxi;
    }
};