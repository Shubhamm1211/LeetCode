class Solution {
private:
    bool solve(string&s, int i, int tar) {
        if(i==s.size() && tar==0) return true;
        if(tar<0) return false;

        int temp=0;
        for(int j=i;j<s.size();j++) {
            temp =(temp*10)+(s[j]-'0');
            if(solve(s,j+1,tar-temp)) {
                return true;
            }
        }
        return false;
    }
public:
    int punishmentNumber(int n) {
        int sum = 0;
        for(int i=1;i<=n;i++){
            int sq=i*i;
            string s=to_string(sq);
            if(solve(s,0,i))sum=sum+sq;
        }
        return sum;
    }
};