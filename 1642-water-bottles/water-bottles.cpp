class Solution {
public:
    int numWaterBottles(int n, int k) {
        int sum=0;
        int left= 0;
        while(n>0)
        {
            sum+=n;
            left+=n;
            n=(left/k);
            left=left%k;
        }
        
        return sum;
    }
};