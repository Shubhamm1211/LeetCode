class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxi=0;
        int mini=prices[0];
        for(int i=0;i<n;i++){
            int diff=prices[i]-mini;
            maxi=max(maxi,diff);
            mini=min(mini,prices[i]);
        }
        return maxi;
    }
};