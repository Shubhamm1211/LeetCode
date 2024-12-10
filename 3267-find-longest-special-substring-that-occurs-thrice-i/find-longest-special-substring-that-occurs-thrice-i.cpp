class Solution {
public:
    bool check(string s){
        set<char>st(s.begin(),s.end());
        if(st.size()==1)return true;
        else return false;
    }
    int maximumLength(string s) {
        unordered_map<string,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n;j++){
                temp=temp+s[j];
                cout<<temp<<" ";
                if(check(temp))mp[temp]++;
            }
            
        }
        cout<<endl;
        size_t ans=0;
        for(auto x:mp){
            if(x.second>=3){
                ans=max(ans,x.first.size());
            }
        }
        if(ans==0)return -1;
        return ans;
    }
};