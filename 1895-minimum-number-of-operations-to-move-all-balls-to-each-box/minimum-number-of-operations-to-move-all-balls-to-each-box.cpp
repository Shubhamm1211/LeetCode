#define ll long long
class Solution {
public:
    vector<int> minOperations(string s) {
        ll n = s.size();
        ll cntL = 0, cntR = 0;
        ll pre = 0, suff = 0;
        vector <int> ans(n,0);
        for(ll i = 0; i < n; i++){
            ans[i] += (cntL * i) - pre;
            if(s[i] == '1'){
                cntL++;
                pre += i;
            }
        }
        for(ll i = n - 1; i >= 0; i--){
            ans[i] += abs((cntR * i) - suff);
            if(s[i] == '1'){
                cntR++;
                suff += i;
            }
        }
        return ans;
    }
};