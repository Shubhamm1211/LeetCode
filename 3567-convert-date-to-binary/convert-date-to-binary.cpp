class Solution {
public:
    string to_binary(int n){
        string ans="";
        while(n>0){
            if(n%2==0){
                ans.push_back('0');
            }
            else ans.push_back('1');
            n=n/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string convertDateToBinary(string date) {
        string y=date.substr(0,4);
        string m=date.substr(5,2);
        string d=date.substr(8,2);
        string ans=to_binary(stoi(y)) + '-' + to_binary(stoi(m)) + '-' + to_binary(stoi(d));
        return ans;
    }
};