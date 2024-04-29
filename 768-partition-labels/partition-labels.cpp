class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        vector<int>ans;
        // for(auto it:mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        int maxi=0;
        int prev=-1;
        for(int i=0;i<s.size();i++){
            maxi=max(maxi,mp[s[i]]);
            // cout<<"maxi = "<<maxi<<endl;
            if(i==maxi){
                ans.push_back(maxi-prev);
                prev=maxi;
            }
        }
        return ans;
    }
};
