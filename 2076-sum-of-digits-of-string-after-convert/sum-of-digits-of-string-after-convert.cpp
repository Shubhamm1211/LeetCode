class Solution {
public:
    int sod(int n){
        int ans=0;
        while(n>0){
            ans=ans+n%10;
            n=n/10;
        }
        return ans;
    }
    int getLucky(string s, int k) {
        int con=0;
        for(int i=0;i<s.size();i++){
            int charval=(s[i]-'a'+1);
            con=con+sod(charval);
        }
        k--;
        int ans=con;
        while(k--){
            ans=sod(ans);
        }
        return ans;
    }
};