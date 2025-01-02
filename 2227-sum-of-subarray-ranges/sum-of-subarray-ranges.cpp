#define ll long long
const int MOD = 1e9 + 7;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        ll n = nums.size();
        vector <ll> nsr(n), nsl(n), ngr(n), ngl(n);
        stack <pair<ll,ll>> st;
        for(ll i = 0; i < n; i++){ // nsl
            if(st.empty()){
                st.push({nums[i],i});
                nsl[i] = -1;
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
        // --------------
        while(!st.empty()) st.pop();
        for(ll i = n - 1; i >= 0; i--){ // nsr
            if(st.empty()){
                st.push({nums[i],i});
                nsr[i] = n;
            }
            else{
                while(!st.empty() and st.top().first > nums[i]){
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
        //----------
        while(!st.empty()) st.pop();
        for(ll i = 0; i < n; i++){ // ngl
            if(st.empty()){
                st.push({nums[i],i});
                ngl[i] = -1;
            }
            else{
                while(!st.empty() and st.top().first <= nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    ngl[i] = -1;
                }
                else{
                    ngl[i] = st.top().second;
                }
                st.push({nums[i], i});
            }
        }
        //---------
        while(!st.empty()) st.pop();
        for(ll i = n - 1; i >= 0; i--){ // ngr
            if(st.empty()){
                st.push({nums[i],i});
                ngr[i] = n;
            }
            else{
                while(!st.empty() and st.top().first < nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    ngr[i] = n;
                }
                else{
                    ngr[i] = st.top().second;
                }
                st.push({nums[i], i});
            }
        }
        ll maxi = 0, mini = 0;
        for(ll i = 0; i < n; i++){
            ll d1 = ngr[i] - i;
            ll d2 = i - ngl[i];
            maxi += d1 * d2 * nums[i];
            
            ll d11 = nsr[i] - i;
            ll d22 = i - nsl[i];
            mini += d11 * d22 * nums[i];
        }
        return maxi - mini;
    }
};