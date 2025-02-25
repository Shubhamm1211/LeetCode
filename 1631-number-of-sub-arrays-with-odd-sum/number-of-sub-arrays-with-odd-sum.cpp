const int MOD = 1e9 + 7;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int sum = 0, odd = 0, even = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum & 1){
                odd++;
                ans = (ans % MOD) + 1 + even;
            }
            else{
                even++;
                ans = (ans % MOD) + odd;
            }
        }
        return ans % MOD;
    }
};