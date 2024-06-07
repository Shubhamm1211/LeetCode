class Solution {
public:
    int chalkReplacer(vector<int>&c, int k) {
        long long s=0;
        long long i=0;
        for(auto e:c)s+=e;
        k=k%s;
        while(1){
            if(i==c.size())i=0;
            if(k==0)break;
            if(c[i]>k)break;
            k=k-c[i];
            i++;
        }
        return i;

    }
};