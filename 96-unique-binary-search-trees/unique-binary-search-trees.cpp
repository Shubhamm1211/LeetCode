class Solution {
public:
    int numTrees(int n) {
        int ans=0;
        if(n==1||n==0)
            return 1;
        for(int i=0;i<n;i++)
            ans=ans+numTrees(i)*numTrees(n-i-1);
        return ans;
    }
};