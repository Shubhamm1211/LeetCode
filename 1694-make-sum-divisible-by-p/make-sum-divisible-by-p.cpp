class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long n = nums.size();
        long long sum = 0;
        for(auto x: nums){
            sum = (sum + x)%p ;
        }
        if(sum % p == 0){
            return 0;
        }
        else{
            unordered_map<long long,long long>mp;
            mp[0] = -1;
            long long rem = sum % p;
            long long temp = 0;
            long long mini = INT_MAX;
            for(long long i = 0; i < n; i++){
                temp = (temp + nums[i])%p;
                long long l = (temp - (rem) +p) %p;
                if(mp.find(l) != mp.end()){
                    mini = min(mini, i - mp[l]);
                }
                mp[temp] = i;
            }
            if(mini == n) return -1;
            else return mini;
        }
    }
};