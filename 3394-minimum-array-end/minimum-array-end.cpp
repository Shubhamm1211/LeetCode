#define ll long long
class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        vector <int> xbit(64,0);
        vector <int> nbit(64,0);
        for(int i = 0; i < 32; i++){
            xbit[i] = ((x>>i) & 1);
            nbit[i] = ((n>>i) & 1);
        }
        int i = 0, j = 0;
        while(i < 64){
            if(xbit[i] == 1){
                i++;
            }
            else{
                xbit[i] = nbit[j];
                i++;
                j++;
            }
        }
        ll ans = 0;
        for(int i = 0; i < 64; i++){
            ans += xbit[i] * (1ll << i);
        }
        return ans;
    }
};