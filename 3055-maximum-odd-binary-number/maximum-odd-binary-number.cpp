class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int c1=0,c0=0;
        for(auto x:s){
            if(x=='1')c1++;
            else c0++;
        }
        int n=s.size();
        s[n-1]='1';
        c1--;
        for(int i=0;i<n-1;i++){
            if(c1>0){
                s[i]='1';
                c1--;
            }
            else {
                s[i]='0';
                c0--;
            }
        }
        return s;


    }
};