class Solution {
public:
        int check(string &s,int i,int j)
    {
        while(i < j)
        {
            if(s[i] != s[j])
               return false ;
            i++ ;
            j--;
        }  
        return true ;   
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int maxi=0;
        string ans="";
        ans.push_back(s[0]);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(check(s,i,j)){
                    if(j-i+1>maxi){
                        maxi=j-i+1;
                        ans=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};