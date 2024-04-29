class Solution {
public:
    vector<string> findRestaurant(vector<string>& l1, vector<string>& l2) {
        int n1=l1.size();
        int n2=l2.size();
        map<string,int>mp;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(l1[i]==l2[j]){
                    if(mp[l1[i]]>i+j){
                        mp[l1[i]]=i+j;
                        break;
                    }
                    mp[l1[i]]=i+j;
                }
            }
        }
        int mini=INT_MAX;
        for(auto x:mp){
            if(x.second<mini){
                mini=x.second;
            }
        }
        vector<string>ans;
        for(auto it:mp){
            if(it.second==mini){
                ans.push_back(it.first);
            }
        }
        return ans;

    }
};