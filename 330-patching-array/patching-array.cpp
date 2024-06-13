class Solution {
public:
    int minPatches(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        long long int maxsum=0;
        long long int i=0;
        int ans=0;
        while(maxsum<target){
            if(i<coins.size() and coins[i]<=maxsum+1){
                maxsum=maxsum+coins[i];
                i++;
            }
            else{
                ans++;
                long long int t=maxsum+1;
                maxsum=maxsum+t;
            }
        }
        return ans;
        
    }
};