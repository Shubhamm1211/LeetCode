class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(n < 0) break;
            n = n - i;
            ans++;
        }
        return ans;
    }
};