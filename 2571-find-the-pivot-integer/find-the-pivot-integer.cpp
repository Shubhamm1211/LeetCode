class Solution {
public:
    int pivotInteger(int n) {
        int sumn=(n*(n+1))/2;
        int sump=0;
        for(int i=1;i<=n;i++){
            sump=sump+i;
            if(sumn-sump+i==sump)return i;
        }
        return -1;
    }
};