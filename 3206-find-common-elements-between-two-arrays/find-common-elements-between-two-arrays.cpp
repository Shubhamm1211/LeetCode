class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp1,mp2;
        for(auto x:nums1)mp1[x]++;
        for(auto x:nums2)mp2[x]++;
        int c1=0,c2=0;
        for(auto x:nums1){
            if(mp2.find(x)!=mp2.end() && mp2[x]>=1) c1++;
        }
        for(auto x:nums2){
            if(mp1.find(x)!=mp1.end() && mp1[x]>=1) c2++;
        }
        return {c1,c2};
    }
};