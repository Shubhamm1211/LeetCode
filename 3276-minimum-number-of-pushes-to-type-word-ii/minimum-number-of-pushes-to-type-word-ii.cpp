class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(int i=0;i<word.size();i++){
            mp[word[i]]++;
        }
        if(word.size()<=7)return word.size();
        vector<int>freq;
        for(auto x:mp){
            freq.push_back(x.second);
        }
        sort(freq.begin(),freq.end(),greater<int>());
        int ans=0;
        for(int i=0;i<freq.size();i++){
            if(i<8)ans=ans+freq[i];
            else if(i<16) ans=ans+freq[i]*2;
            else if(i<24) ans=ans+freq[i]*3;
            else ans=ans+freq[i]*4;
        }
        return ans;
    }
};