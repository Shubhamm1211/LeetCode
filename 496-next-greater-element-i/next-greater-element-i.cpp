class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        st.push(-1);
        int n=nums2.size();
        vector<int>nge(n,-1);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                nge[i]=-1;
                st.push(nums2[i]);
            }
            else if(nums2[i]<st.top()){
                nge[i]=st.top();
                st.push(nums2[i]);
            }
            else if(nums2[i]>st.top()){
                while(!st.empty() and st.top()<nums2[i]){
                    st.pop();
                }
                if(!st.empty()){
                nge[i]=st.top();
                }
                else nge[i]=-1;
                st.push(nums2[i]);
            }
        }
        unordered_map<int,int>mp;
        int m=nums1.size();
         for(int i=0;i<n;i++){
            mp[nums2[i]] = i;
        }
        vector<int>ans;
        for(int i=0;i<m;i++){
             int indextofind = nums1[i];
             int indexis = mp[indextofind];
             ans.push_back(nge[indexis]);
        }
        for(auto x:nge)cout<<x<<" ";
        return ans;
    }
};