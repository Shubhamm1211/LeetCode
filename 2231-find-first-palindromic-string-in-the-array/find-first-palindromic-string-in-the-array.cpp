class Solution {
public:
    bool ispalindrome(string str){
        int n=str.size();
        int i=0;
        int j=n-1;
        while(i<=j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        string ans="";
        for(auto str:words){
            if(ispalindrome(str)){
            ans=str;
            break;
            }
        }
        return ans;
    }
};