class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int maxi = 0;
        int s = p[0];
        for(int i = 0; i < n; i++){
            int temp = p[i] - s;
            maxi = max(maxi,temp);
            s = min(s,p[i]);   
        }
        return maxi;
    }
};