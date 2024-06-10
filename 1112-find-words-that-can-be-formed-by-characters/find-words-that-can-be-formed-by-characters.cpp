class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int>mp;
        for(auto c:chars){
            mp[c]++;
        }
        int ans=0;
        for(auto w:words){
            map<char,int>mp2;
            for(auto c:w){
                mp2[c]++;
            }
            bool flag=true;
            for(auto x:mp2){
                cout<<x.first<<" "<<x.second<<endl;
                if(mp.find(x.first)==mp.end()||x.second>mp[x.first]){
                    flag=false;
                }
            }
            if(flag)ans=ans+w.size();
        }
        return ans;
    }
};