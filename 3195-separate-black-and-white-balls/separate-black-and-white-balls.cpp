#define ll long long
class Solution {
public:
    long long minimumSteps(string s) {
        ll n = s.size();
        ll cnt = 0, ans = 0;
        for(ll i = 0; i < n; i++){
            if(s[i] == '0'){
                ans += cnt;
            }
            else cnt++;
        }
        return ans;
    }
};