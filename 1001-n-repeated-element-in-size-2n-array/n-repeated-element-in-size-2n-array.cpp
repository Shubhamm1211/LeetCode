class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int n=nums.size()/2;
        for(auto x:mp){
            if(x.second==n)return x.first;
        }
        return 0;
    }
};