class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
                mp.clear();
                cnt++;
            }
            mp[s[i]]++;
        }
        return cnt+1;
    }
};