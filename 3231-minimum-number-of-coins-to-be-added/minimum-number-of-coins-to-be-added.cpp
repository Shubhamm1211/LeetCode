class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        int maxsum=0;
        int i=0;
        int ans=0;
        while(maxsum<target){
            if(i<coins.size() and coins[i]<=maxsum+1){
                maxsum=maxsum+coins[i];
                i++;
            }
            else{
                ans++;
                int t=maxsum+1;
                maxsum=maxsum+t;
            }
        }
        return ans;
        
       
    }
};