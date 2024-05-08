#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rev(int n){
        int ans=0;
        while(n){
            int d=n%10;
            ans=(ans*10)+d;
            n=n/10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        map<long long int,long long int>mp;
        int n=nums.size();
        long long int ans=0;
        for(int i=0;i<n;i++){
            nums[i]=nums[i]-rev(nums[i]);
            ans=ans+mp[nums[i]];
            mp[nums[i]]++;
        }
        return ans%1000000007;
    }
};