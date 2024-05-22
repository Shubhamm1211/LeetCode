class Solution {
public:
    bool check(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(vector<vector<string>>&ans,vector<string>&ds,int n,int i,string s){
        if(i==n)ans.push_back(ds);
        for(int j=i;j<n;j++){
            string sub=s.substr(i,j-i+1);
            if(check(sub)){
                ds.push_back(sub);
                solve(ans,ds,n,j+1,s);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        int n=s.size();
        solve(ans,ds,n,0,s);
        return ans;
    }
};