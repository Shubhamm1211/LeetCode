#define ll long long int
#define mod 1000000007
class Solution {
public:
    ll pows(ll x,ll n){
        if(n==0){
            return 1;
        }
        long long ans=pows(x,n/2);
        ans*=ans;
        ans%=mod;
        if(n%2==1){
            ans*=x;
            ans%=mod;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        ll o=n/2;
        ll e=n/2 + n%2;
        ll ans=(pows(5,e)*pows(4,o))%mod;
        return ans;
    }
};