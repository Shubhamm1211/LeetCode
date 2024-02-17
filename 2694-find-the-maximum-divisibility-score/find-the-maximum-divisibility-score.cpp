
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int cnt1 = 0, cnt2 = 0,ans = INT_MAX;
        for(auto i: divisors){
            cnt1 = 0;
            for(auto j: nums){
                if(j%i==0){
                    cnt1++;
                }
            }
            if(cnt1>cnt2){
                cnt2 = cnt1;
                ans = i;
            }
            if(cnt1==cnt2){
                ans = min(ans,i);
            }
        }
        return ans;
    }
};