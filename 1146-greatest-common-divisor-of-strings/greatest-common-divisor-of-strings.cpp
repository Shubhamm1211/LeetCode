class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1){
            return "";
        }
        else{
            int s1=str1.size();
            int s2=str2.size();
            int g=gcd(s1,s2);
            string ans=str1.substr(0,g);
            return ans;
        }
    }
};