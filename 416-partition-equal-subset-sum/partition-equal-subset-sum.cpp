class Solution {
public:
    bool solve(vector <int> &arr, int sum, int ind,vector <vector<int>>&dp){
        if(sum == 0){
            return true;
        }
        if(ind == 0){
            if(arr[ind] == sum){
                return true;
            }
            return false;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum] ;
        bool pick = false;
        if(sum - arr[ind] >= 0){
             pick = solve(arr,sum - arr[ind], ind - 1,dp);
        }
        bool notpick = solve(arr,sum, ind - 1,dp);
        
        return dp[ind][sum] = (pick or notpick) ;
    }
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(begin(arr), end(arr), 0);
        if(sum % 2 == 1) return false;
        else{
            sum /= 2;
            vector <vector<int>> dp(n + 1,vector<int>(sum + 1,-1));
            return solve(arr, sum, n - 1,dp);
        }
    }
};