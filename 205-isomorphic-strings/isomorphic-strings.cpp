class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        map<char,char>mp;
        set<char>st;
        for(int i=0;i<n;i++){
            st.insert(t[i]);
            
            if(mp[s[i]]>0){
                if(mp[s[i]]!=t[i])return false;
            }
            else{
                mp[s[i]]=t[i];
            }
            if(st.size()!=mp.size())return false;
        }
        return true;
    }
};