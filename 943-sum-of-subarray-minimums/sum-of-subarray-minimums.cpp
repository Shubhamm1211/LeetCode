const int MOD = 1e9 + 7;
#define ll long long
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector <int> nsr(n), nsl(n);
        stack<pair<int,int>> st;
        for(int i = 0; i < n; i++){
            if(st.empty()){
                nsl[i] = -1; 
            }
            else{
                while(!st.empty() and st.top().first >= arr[i]){
                    st.pop();
                }
                if(st.empty()) nsl[i] = -1;
                else nsl[i] = st.top().second;
            }
            st.push({arr[i], i});
        }
        while(!st.empty()) st.pop();
        for(int i = n - 1; i >= 0; i--){
            if(st.empty()){
                nsr[i] = n;
            }
            else{
                while(!st.empty() and st.top().first > arr[i]){
                    st.pop();
                }
                if(st.empty()) nsr[i] = n;
                else nsr[i] = st.top().second;
            }
            st.push({arr[i], i});
        }
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll d1 = i - nsl[i];
            ll d2 = nsr[i] - i;
            ans += (d1 * d2 * arr[i]) % MOD;
            ans = ans % MOD;
        }
        return ans;
    }
};