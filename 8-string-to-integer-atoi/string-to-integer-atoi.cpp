class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        long long ans=0;
        int flag;
        while(i<n){
            while(s[i]==' ' and i<n)i++;
            if(i==n)break;
            if(isdigit(s[i])){
                flag=1;
                while(isdigit(s[i])){
                    ans=ans*10+(s[i]-'0');
                    if(ans>=INT_MAX)return INT_MAX;
                    i++;
                }
                break;
            }
            if(s[i]=='+'){
                flag=1;
                i++;
                while(isdigit(s[i])){
                    ans=ans*10+(s[i]-'0');
                    if(ans>=INT_MAX)return INT_MAX;
                    i++;
                }
                break;
        }
            else if(s[i]=='-'){
                flag=-1;
                i++;
                while(isdigit(s[i])){
                    ans=ans*10+(s[i]-'0');
                    if(ans*flag<=INT_MIN) return INT_MIN;
                    i++;
                }
                break;
            }
            else break;
        }
        ans=ans*flag;
        return ans;
    }
};