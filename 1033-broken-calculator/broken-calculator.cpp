class Solution {
public:
    int brokenCalc(int s, int t) {
        int ans = 0;
        while (t>s) {
            ans++;
            if (t%2==0) {
                t/=2;
            } else {
                t++;
            }
        }
        return ans+(s-t);
    }
};
