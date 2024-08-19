class Solution {
public:
    int solve(int curr,int clip,int tar){
        if(curr==tar)return 0;
        if(curr>tar)return INT_MAX/2;
        int cp=2+solve(curr*2,curr,tar);
        int p=1+solve(curr+clip,clip,tar);
        return min(cp,p);
    }
    int minSteps(int n) {
        if(n==1)return 0;
        return 1+solve(1,1,n);
    }
};