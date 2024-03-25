class Solution {
public:
    string truncateSentence(string s, int k) {
        int n=s.size();
        int sc=0;
        string ans="";
        int i=0;
        for(int i=0;i<n && sc<k;i++){
            if(s[i]==' ')sc++;
            ans=ans+s[i];
        }
        if(ans[ans.size()-1]==' ')ans.pop_back();
        return ans;
    }
};