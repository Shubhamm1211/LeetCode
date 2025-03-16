#define ll long long
class Solution {
public:
    bool solve(vector <int> &nums, int cars, ll mid){
        ll cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            cnt += sqrt(mid / (nums[i] * 1.0));
        }
        return cnt >= cars;
    }
    long long repairCars(vector<int>& nums, int cars) {
        ll n = nums.size();
        ll low = 1, high = 1e15;
        ll ans = -1;
        while(low <= high){
            ll mid = low + ((high - low) / 2);
            if(solve(nums,cars,mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        } 
        return ans;
    }
};