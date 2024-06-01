class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>mp1,mp2;
        int n1=s1.size();
        int n2=s2.size();
        for(auto x:s1){
            mp1[x]++;
        }
        int l=0,r=0;
        while(r<n2){
            mp2[s2[r]]++;
            if(r-l+1==n1){
                if(mp1==mp2)return true;
                mp2[s2[l]]--;
                if(mp2[s2[l]]==0)mp2.erase(s2[l]);
                l++;
            }
            r++;
        }
        return false;
    }
};