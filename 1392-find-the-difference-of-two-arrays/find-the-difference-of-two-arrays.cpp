class Solution {
public:
    bool findd(int n,vector<int>v){
        for(int i=0;i<v.size();i++){
            if(v[i]==n)return true;
        }
        return false;
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int>t1;
        vector<int>t2;
        vector<vector<int>>ans;
        map<int,int>mp1;
        map<int,int>mp2;
        for(auto it:nums1)mp1[it]++;
        for(auto it:nums2)mp2[it]++;
        for(int i=0;i<nums1.size();i++){
            if(mp2.find(nums1[i])==mp2.end() && findd(nums1[i],t1)==false)t1.push_back(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            if(mp1.find(nums2[i])==mp1.end() && findd(nums2[i],t2)==false)t2.push_back(nums2[i]);
        }
        ans.push_back(t1);
        ans.push_back(t2);
        return ans;
    }
};