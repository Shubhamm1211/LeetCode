#define ll long long
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        ll n = nums.size();
        ll maxi = INT_MIN;
        ll maxpos = 0;
        ll maxneg = 0;
        ll sum = 0;
        for(ll i = 0; i < n; i++){
            sum += nums[i];
            if(sum >= 0 and sum > maxpos){
                maxpos = sum;
            }
            if(sum < 0 and sum < maxneg){
                maxneg = sum;
            } 
            if(sum >= 0){
                maxi = max(maxi, sum - maxneg);
            }
            else if(sum < 0){
                maxi = max(maxi, abs(sum - maxpos));
            }
        }
        return maxi;
    }
};