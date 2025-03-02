class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map <int,int> mp;
        for(int i = 0; i < nums1.size(); i++){
            int id = nums1[i][0];
            int val = nums1[i][1];
            if(mp.find(id) != mp.end()) mp[id] += val;
            else mp[id] = val;
        }
        for(int i = 0; i < nums2.size(); i++){
            int id = nums2[i][0];
            int val = nums2[i][1];
            if(mp.find(id) != mp.end()) mp[id] += val;
            else mp[id] = val;
        }
        vector<vector<int>> ans;
        for(auto &x : mp){
            ans.push_back({x.first, x.second});
        }
        return ans;
    }
};