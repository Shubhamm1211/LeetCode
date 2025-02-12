class Solution {
public:
    int sod(int n){
        int sum = 0;
        while(n){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        map <int,vector<int>> mp;
        for(int i = 0; i < n; i++){
            int sum = sod(nums[i]);
            if(mp.find(sum) != mp.end()){
                mp[sum].push_back(nums[i]);
            }
            else{
                mp[sum].push_back(nums[i]);
            }
        }
        int maxi = INT_MIN;
        for(auto &x : mp){
            if(x.second.size() >= 2){
                sort(begin(x.second), end(x.second));
                maxi = max(maxi, x.second[x.second.size() - 1] + x.second[x.second.size() - 2]);
            }
        }
        return (maxi == INT_MIN) ? -1 : maxi;
    }
};